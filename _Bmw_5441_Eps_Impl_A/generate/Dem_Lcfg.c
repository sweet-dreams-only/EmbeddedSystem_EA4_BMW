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
 *            Module: Dem
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:09
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



/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0810 EOF */ /* MD_MSR_1.1_810 */                                      /* #include "..." causes nesting to exceed 8 levels - program is non-conforming. -- caused by #include'd files. */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_DEM_5.1 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#include "Os.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                               /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                           /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_DemMaster_0.h"
#endif
#include "Dem_AdditionalIncludeCfg.h"                                           /* additional, configuration defined files */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_Cfg_CallbackClearEventAllowed
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_ClearEventAllowedFPtrType, DEM_CONST) Dem_Cfg_CallbackClearEventAllowed[3] = {
  /* Index     CallbackClearEventAllowed                                    Referable Keys */
  /*     0 */ NULL_PTR                                                ,  /* [#NoCallbackEventDataChangedConfigured] */
  /*     1 */ Rte_Call_CBClrEvt_CodingEventNotCoded_ClearEventAllowed ,  /* [CodingEventNotCoded] */
  /*     2 */ Rte_Call_CBClrEvt_VsmEventOpmode_ClearEventAllowed         /* [VsmEventOpmode] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CombinedGroups
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CombinedGroups
  \details
  Element                     Description
  CombinedEventIdsStartIdx    the start index of the 1:n relation pointing to Dem_Cfg_CombinedEventIds
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_CombinedGroupsType, DEM_CONST) Dem_Cfg_CombinedGroups[2] = {
    /* Index    CombinedEventIdsStartIdx        Referable Keys */
  { /*     0 */                       0U },  /* [CEG_Primary_DTC_4822E4] */
  { /*     1 */                       2U }   /* [CEG_Primary_DTC_4822F5] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTable
  \details
  Element                                Description
  IdNumber                           
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  MaskedBits                             contains bitcoded the boolean data of Dem_Cfg_DataElementTableCol2ElmtIndUsedOfDataCollectionTable, Dem_Cfg_UpdateOfDataCollectionTable
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[14] = {
    /* Index    IdNumber  CollectionSize  DataElementTableCol2ElmtIndEndIdx                                  DataElementTableCol2ElmtIndStartIdx                                  MaskedBits  StorageKind                     Referable Keys */
  { /*     0 */  0x0000U,             0U, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE,      0x00U, DEM_CFG_EREC_TYPE_GLOBAL },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x0001U,             1U,                                                                1U,                                                                  0U,      0x03U, DEM_CFG_EREC_TYPE_USER   },  /* [#EdrConditionByte, Ext:ExtendedDataClass_DTC_023000_Props, Ext:ExtendedDataClass_DTC_023008_Props, Ext:ExtendedDataClass_DTC_023009_Props, Ext:ExtendedDataClass_DTC_02300A_Props, Ext:ExtendedDataClass_DTC_023040_Props, Ext:ExtendedDataClass_DTC_023041_Props, Ext:ExtendedDataClass_DTC_023042_Props, Ext:ExtendedDataClass_DTC_023043_Props, Ext:ExtendedDataClass_DTC_023044_Props, Ext:ExtendedDataClass_DTC_023045_Props, Ext:ExtendedDataClass_DTC_02FF30_Props, Ext:ExtendedDataClass_DTC_D5041F_Props, Ext:ExtendedDataClass_DTC_D50420_Props, Ext:ExtendedDataClass_DTC_D50BFF_Props] */
  { /*     2 */  0x0003U,             1U,                                                                2U,                                                                  1U,      0x03U, DEM_CFG_EREC_TYPE_USER   },  /* [#EdrHealingCounter, Ext:ExtendedDataClass_DTC_D5041F_Props, Ext:ExtendedDataClass_DTC_D50420_Props] */
  { /*     3 */  0x0002U,             1U,                                                                3U,                                                                  2U,      0x03U, DEM_CFG_EREC_TYPE_USER   },  /* [#EdrOccurrenceCounter, Ext:ExtendedDataClass_DTC_023000_Props, Ext:ExtendedDataClass_DTC_023008_Props, Ext:ExtendedDataClass_DTC_023009_Props, Ext:ExtendedDataClass_DTC_02300A_Props, Ext:ExtendedDataClass_DTC_023040_Props, Ext:ExtendedDataClass_DTC_023041_Props, Ext:ExtendedDataClass_DTC_023042_Props, Ext:ExtendedDataClass_DTC_023043_Props, Ext:ExtendedDataClass_DTC_023044_Props, Ext:ExtendedDataClass_DTC_023045_Props, Ext:ExtendedDataClass_DTC_02FF30_Props, Ext:ExtendedDataClass_DTC_D5041F_Props, Ext:ExtendedDataClass_DTC_D50420_Props, Ext:ExtendedDataClass_DTC_D50BFF_Props] */
  { /*     4 */  0x2805U,             1U,                                                                4U,                                                                  3U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidAussentemperatur, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props] */
  { /*     5 */  0x2866U,             1U,                                                                5U,                                                                  4U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidBetriebsspannung, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props] */
  { /*     6 */  0x1750U,             1U,                                                                6U,                                                                  5U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidFUwBn, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*     7 */  0x2867U,             1U,                                                                7U,                                                                  6U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidFahrzeuggeschwindigkeit, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props] */
  { /*     8 */  0x5003U,             2U,                                                                8U,                                                                  7U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidHwAg, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*     9 */  0x500EU,             2U,                                                                9U,                                                                  8U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidHwTq, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*    10 */  0x1700U,             3U,                                                               10U,                                                                  9U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidKmStand, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*    11 */  0x500FU,             2U,                                                               11U,                                                                 10U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidMotTq, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*    12 */  0x500CU,             2U,                                                               12U,                                                                 11U,      0x02U, DEM_CFG_EREC_TYPE_USER   },  /* [#DidPscmSts, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  { /*    13 */  0x1701U,             4U,                                                               13U,                                                                 12U,      0x02U, DEM_CFG_EREC_TYPE_USER   }   /* [#DidSystemzeit, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:DemFreezeFrameClass_Systemzeit, Ffm:FreezeFrameClass_DTC_023000_Props, Ffm:FreezeFrameClass_DTC_023008_Props, Ffm:FreezeFrameClass_DTC_023009_Props, Ffm:FreezeFrameClass_DTC_02300A_Props, Ffm:FreezeFrameClass_DTC_023040_Props, Ffm:FreezeFrameClass_DTC_023041_Props, Ffm:FreezeFrameClass_DTC_023042_Props, Ffm:FreezeFrameClass_DTC_023043_Props, Ffm:FreezeFrameClass_DTC_023044_Props, Ffm:FreezeFrameClass_DTC_023045_Props, Ffm:FreezeFrameClass_DTC_02FF30_Props, Ffm:FreezeFrameClass_DTC_D5041F_Props, Ffm:FreezeFrameClass_DTC_D50420_Props, Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableEdr2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableEdr2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableEdr2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableEdr2CollInd[30] = {
  /* Index     DataCollectionTableEdr2CollInd      Referable Keys */
  /*     0 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023000_Props] */
  /*     1 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023000_Props] */
  /*     2 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023008_Props] */
  /*     3 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023008_Props] */
  /*     4 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023009_Props] */
  /*     5 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023009_Props] */
  /*     6 */                              1U,  /* [Ext:ExtendedDataClass_DTC_02300A_Props] */
  /*     7 */                              3U,  /* [Ext:ExtendedDataClass_DTC_02300A_Props] */
  /*     8 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023040_Props] */
  /*     9 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023040_Props] */
  /*    10 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023041_Props] */
  /*    11 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023041_Props] */
  /*    12 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023042_Props] */
  /*    13 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023042_Props] */
  /*    14 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023043_Props] */
  /*    15 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023043_Props] */
  /*    16 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023044_Props] */
  /*    17 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023044_Props] */
  /*    18 */                              1U,  /* [Ext:ExtendedDataClass_DTC_023045_Props] */
  /*    19 */                              3U,  /* [Ext:ExtendedDataClass_DTC_023045_Props] */
  /*    20 */                              1U,  /* [Ext:ExtendedDataClass_DTC_02FF30_Props] */
  /*    21 */                              3U,  /* [Ext:ExtendedDataClass_DTC_02FF30_Props] */
  /*    22 */                              1U,  /* [Ext:ExtendedDataClass_DTC_D5041F_Props] */
  /*    23 */                              3U,  /* [Ext:ExtendedDataClass_DTC_D5041F_Props] */
  /*    24 */                              2U,  /* [Ext:ExtendedDataClass_DTC_D5041F_Props] */
  /*    25 */                              1U,  /* [Ext:ExtendedDataClass_DTC_D50420_Props] */
  /*    26 */                              3U,  /* [Ext:ExtendedDataClass_DTC_D50420_Props] */
  /*    27 */                              2U,  /* [Ext:ExtendedDataClass_DTC_D50420_Props] */
  /*    28 */                              1U,  /* [Ext:ExtendedDataClass_DTC_D50BFF_Props] */
  /*    29 */                              3U   /* [Ext:ExtendedDataClass_DTC_D50BFF_Props] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableFfm2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableFfm2CollInd[148] = {
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*     0 */                             13U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     1 */                              4U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     2 */                              5U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     3 */                              7U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     4 */                              6U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     5 */                              8U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     6 */                              9U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     7 */                             10U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     8 */                             11U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*     9 */                             12U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*    10 */                             13U,  /* [Ffm:DemFreezeFrameClass_Systemzeit] */
  /*    11 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    12 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    13 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    14 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    15 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    16 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    17 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    18 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    19 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    20 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023000_Props] */
  /*    21 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    22 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    23 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    24 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    25 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    26 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    27 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    28 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    29 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    30 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023008_Props] */
  /*    31 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    32 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    33 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    34 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    35 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    36 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    37 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    38 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    39 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    40 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023009_Props] */
  /*    41 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    42 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    43 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    44 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    45 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    46 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    47 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    48 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    49 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*    50 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_02300A_Props] */
  /*    51 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    52 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    53 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    54 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    55 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    56 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    57 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    58 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    59 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    60 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023040_Props] */
  /*    61 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    62 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    63 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    64 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    65 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    66 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    67 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    68 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    69 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    70 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023041_Props] */
  /*    71 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    72 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    73 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    74 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    75 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    76 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    77 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    78 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    79 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    80 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023042_Props] */
  /*    81 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    82 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    83 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    84 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    85 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    86 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    87 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    88 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    89 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    90 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023043_Props] */
  /*    91 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    92 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    93 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    94 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    95 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    96 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    97 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    98 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*    99 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*   100 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023044_Props] */
  /*   101 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   102 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   103 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   104 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   105 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   106 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   107 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   108 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   109 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   110 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_023045_Props] */
  /*   111 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   112 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   113 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   114 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   115 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   116 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   117 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   118 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   119 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   120 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_02FF30_Props] */
  /*   121 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   122 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   123 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   124 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   125 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   126 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   127 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   128 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   129 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   130 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_D5041F_Props] */
  /*   131 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   132 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   133 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   134 */                              4U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   135 */                              5U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   136 */                              7U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   137 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   138 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   139 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   140 */                             12U,  /* [Ffm:FreezeFrameClass_DTC_D50420_Props] */
  /*   141 */                              6U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   142 */                             10U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   143 */                             13U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   144 */                              8U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   145 */                              9U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   146 */                             11U,  /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
  /*   147 */                             12U   /* [Ffm:FreezeFrameClass_DTC_D50BFF_Props] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTable
  \details
  Element         Description
  ElementKind     DataElement kind, returned by Dem_Cfg_DataCallbackType()
  ElementSize     Size of data element in Byte.
  ReadDataFunc    C-function for getting the data. Its signature depends on ElementKind: With value(s) DEM_CFG_DATA_FROM_CBK_WITH_EVENTID use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId); - and use: Std_ReturnType (*)(uint8* Buffer); with the other values DEM_CFG_DATA_FROM_CBK, DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN, DEM_CFG_DATA_FROM_SR_PORT_SINT16, DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL, DEM_CFG_DATA_FROM_SR_PORT_SINT32, DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL, DEM_CFG_DATA_FROM_SR_PORT_SINT8, DEM_CFG_DATA_FROM_SR_PORT_SINT8_N, DEM_CFG_DATA_FROM_SR_PORT_UINT16, DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL, DEM_CFG_DATA_FROM_SR_PORT_UINT32, DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL, DEM_CFG_DATA_FROM_SR_PORT_UINT8, DEM_CFG_DATA_FROM_SR_PORT_UINT8_N.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[14] = {
    /* Index    ElementKind                  ElementSize  ReadDataFunc                                                                                                                     Referable Keys */
  { /*     0 */ DEM_CFG_DATAELEMENT_INVALID,          0U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                      },  /* [#NoDataElementConfigured] */
  { /*     1 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_2866_Betriebsspannung_ReadData        },  /* [#DID_2866_Betriebsspannung, DidBetriebsspannung] */
  { /*     2 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_1750_FUwBn_ReadData                   },  /* [#DID_1750_FUwBn, DidFUwBn] */
  { /*     3 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_2805_Aussentemperatur_ReadData        },  /* [#DID_2805_Aussentemperatur, DidAussentemperatur] */
  { /*     4 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EDR_02_OccurrenceCounter_ReadData         },  /* [#EDR_02_OccurrenceCounter, EdrOccurrenceCounter] */
  { /*     5 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_2867_Fahrzeuggeschwindigkeit_ReadData },  /* [#DID_2867_Fahrzeuggeschwindigkeit, DidFahrzeuggeschwindigkeit] */
  { /*     6 */ DEM_CFG_DATA_FROM_CBK      ,          4U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_1701_Systemzeit_ReadData              },  /* [#DID_1701_Systemzeit, DidSystemzeit] */
  { /*     7 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EDR_03_HealingCounter_ReadData            },  /* [#EDR_03_HealingCounter, EdrHealingCounter] */
  { /*     8 */ DEM_CFG_DATA_FROM_CBK      ,          3U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_1700_KmStand_ReadData                 },  /* [#DID_1700_KmStand, DidKmStand] */
  { /*     9 */ DEM_CFG_DATA_FROM_CBK      ,          1U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_EDR_01_ConditionByte_ReadData             },  /* [#EDR_01_ConditionByte, EdrConditionByte] */
  { /*    10 */ DEM_CFG_DATA_FROM_CBK      ,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_5003_HwAg_ReadData                    },  /* [#DID_5003_HwAg, DidHwAg] */
  { /*    11 */ DEM_CFG_DATA_FROM_CBK      ,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_500C_PscmSts_ReadData                 },  /* [#DID_500C_PscmSts, DidPscmSts] */
  { /*    12 */ DEM_CFG_DATA_FROM_CBK      ,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_500E_HwTq_ReadData                    },  /* [#DID_500E_HwTq, DidHwTq] */
  { /*    13 */ DEM_CFG_DATA_FROM_CBK      ,          2U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_500F_MotTq_ReadData                   }   /* [#DID_500F_MotTq, DidMotTq] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableCol2ElmtInd[13] = {
  /* Index     DataElementTableCol2ElmtInd      Referable Keys */
  /*     0 */                           9U,  /* [EdrConditionByte] */
  /*     1 */                           7U,  /* [EdrHealingCounter] */
  /*     2 */                           4U,  /* [EdrOccurrenceCounter] */
  /*     3 */                           3U,  /* [DidAussentemperatur] */
  /*     4 */                           1U,  /* [DidBetriebsspannung] */
  /*     5 */                           2U,  /* [DidFUwBn] */
  /*     6 */                           5U,  /* [DidFahrzeuggeschwindigkeit] */
  /*     7 */                          10U,  /* [DidHwAg] */
  /*     8 */                          12U,  /* [DidHwTq] */
  /*     9 */                           8U,  /* [DidKmStand] */
  /*    10 */                          13U,  /* [DidMotTq] */
  /*    11 */                          11U,  /* [DidPscmSts] */
  /*    12 */                           6U   /* [DidSystemzeit] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceTable
  \details
  Element                   Description
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_Cfg_DebounceContinuousOfDebounceTable, Dem_Cfg_EventDebounceBehaviorOfDebounceTable, Dem_Cfg_JumpDownOfDebounceTable, Dem_Cfg_JumpUpOfDebounceTable, Dem_Cfg_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DebounceTableType, DEM_CONST) Dem_Cfg_DebounceTable[2] = {
    /* Index    DecrementStepSize  FailedThreshold  IncrementStepSize  PassedThreshold  EventDebounceAlgorithm                                                      MaskedBits        Referable Keys */
  { /*     0 */                -1,             127,                 1,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06U },  /* [CodingEventNotCoded, CodingEventUnqualifiedData, CodingEventWrongVehicle, DIO_E_REG_WRITE_VERIFY, DmTestAppl, DmTestCom, FLS_E_COMPARE_FAILED, FLS_E_ECC_FAILED, FLS_E_ERASE_FAILED, FLS_E_HW_FAILURE, FLS_E_INT_INCONSISTENT, FLS_E_READ_FAILED, FLS_E_READ_FAILED_DED, FLS_E_REG_WRITE_VERIFY, FLS_E_UNEXPECTED_FLASH_ID, FLS_E_WRITE_FAILED, FrsmEClusterSyncLoss, FrtrcvEFrBuserrorTrcv0, GlobalOvervoltageExt, GlobalOvervoltageInt, GlobalUndervoltageExt, GlobalUndervoltageInt, LocalOvervoltage, LocalUndervoltage, MCU_E_CLM_SELFDIAG_FAILURE, MCU_E_CLOCK_FAILURE, MCU_E_CVM_SELFDIAG_FAILURE, MCU_E_ECM_SELFDIAG_FAILURE, MCU_E_INT_INCONSISTENT, MCU_E_LOCKSTEP_SELFDIAG_FAILURE, MCU_E_REG_WRITE_VERIFY, MCU_E_RESETCONTROLLER_STARTUP_FAILURE, MCU_E_WRITE_TIMEOUT_FAILURE, PORT_E_REG_WRITE_VERIFY, PORT_E_WRITE_TIMEOUT_FAILURE, PriEve4822E4_SecEve21F100, PriEve4822E4_SecEve31F100, PriEve4822F5_SecEve21F300, PriEve4822F5_SecEve31F300, SPI_E_DATA_TX_TIMEOUT_FAILURE, SPI_E_ECC_SELFTEST_FAILURE, SPI_E_HARDWARE_ERROR, SPI_E_INT_INCONSISTENT, SPI_E_LOOPBACK_SELFTEST_FAILURE, SPI_E_REG_WRITE_VERIFY, SecondaryEve_20F300, SecondaryEve_21F100, SecondaryEve_21F300, SecondaryEve_30F300, SecondaryEve_31F100, SecondaryEve_31F300, VsmEventOpmode, WDGM_E_IMPROPER_CALLER, WDGM_E_MONITORING, WDGM_E_SET_MODE, WDG_E_DISABLE_REJECTED, WDG_E_INT_INCONSISTENT, WDG_E_MODE_FAILED, WDG_E_REG_WRITE_VERIFY] */
  { /*     1 */                 0,               0,                 0,               0, DEM_CFG_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00U }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcTable
  \details
  Element           Description
  UdsDtc        
  FunctionalUnit
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[23] = {
    /* Index    UdsDtc        FunctionalUnit        Referable Keys */
  { /*     0 */ 0x00FFFFFFUL,           255U },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x00023008UL,             0U },  /* [DTC_023008] */
  { /*     2 */ 0x0002300AUL,             0U },  /* [DTC_02300A] */
  { /*     3 */ 0x00023009UL,             0U },  /* [DTC_023009] */
  { /*     4 */ 0x0002FF30UL,             0U },  /* [DTC_02FF30] */
  { /*     5 */ 0x00D50BFFUL,             0U },  /* [DTC_D50BFF] */
  { /*     6 */ 0x00D50420UL,             0U },  /* [DTC_D50420] */
  { /*     7 */ 0x00D5041FUL,             0U },  /* [DTC_D5041F] */
  { /*     8 */ 0x00023043UL,             0U },  /* [DTC_023043] */
  { /*     9 */ 0x00023042UL,             0U },  /* [DTC_023042] */
  { /*    10 */ 0x00023045UL,             0U },  /* [DTC_023045] */
  { /*    11 */ 0x00023044UL,             0U },  /* [DTC_023044] */
  { /*    12 */ 0x00023040UL,             0U },  /* [DTC_023040] */
  { /*    13 */ 0x00023041UL,             0U },  /* [DTC_023041] */
  { /*    14 */ 0x00023000UL,             0U },  /* [DTC_023000] */
  { /*    15 */ 0x004822E4UL,             0U },  /* [Primary_DTC_4822E4] */
  { /*    16 */ 0x004822F5UL,             0U },  /* [Primary_DTC_4822F5] */
  { /*    17 */ 0x0021F300UL,             0U },  /* [Secondary_DTC_21F300] */
  { /*    18 */ 0x0030F300UL,             0U },  /* [Secondary_DTC_30F300] */
  { /*    19 */ 0x0031F100UL,             0U },  /* [Secondary_DTC_31F100] */
  { /*    20 */ 0x0031F300UL,             0U },  /* [Secondary_DTC_31F300] */
  { /*    21 */ 0x0021F100UL,             0U },  /* [Secondary_DTC_21F100] */
  { /*    22 */ 0x0020F300UL,             0U }   /* [Secondary_DTC_20F300] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupTableInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EnableConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionGroupTableIndType, DEM_CONST) Dem_Cfg_EnableConditionGroupTableInd[10] = {
  /* Index     EnableConditionGroupTableInd      Referable Keys */
  /*     0 */                            0U,  /* [__Internal_ControlDtcSetting] */
  /*     1 */                            3U,  /* [__Internal_ControlDtcSetting] */
  /*     2 */                            1U,  /* [__Internal_ControlDtcSetting] */
  /*     3 */                            2U,  /* [__Internal_ControlDtcSetting] */
  /*     4 */                            2U,  /* [DemEnableCondition_Omc] */
  /*     5 */                            3U,  /* [DemEnableCondition_StdDiag] */
  /*     6 */                            1U,  /* [DemEnableCondition_StdDiag] */
  /*     7 */                            2U,  /* [DemEnableCondition_StdDiag] */
  /*     8 */                            1U,  /* [DemEnableCondition_Stm] */
  /*     9 */                            2U   /* [DemEnableCondition_Stm] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionTable
  \brief  Map each EnableCondition(Id) to the referring EnableConditionGroups - this is reverse direction of the AUTOSAR configuration model.
  \details
  Element                                 Description
  EnableConditionGroupTableIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
  EnableConditionGroupTableIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionTableType, DEM_CONST) Dem_Cfg_EnableConditionTable[4] = {
    /* Index    EnableConditionGroupTableIndEndIdx  EnableConditionGroupTableIndStartIdx */
  { /*     0 */                                 4U,                                   0U },
  { /*     1 */                                 5U,                                   4U },
  { /*     2 */                                 8U,                                   5U },
  { /*     3 */                                10U,                                   8U }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_EventStatusChangedFPtrType, DEM_CONST) Dem_Cfg_EventStatusChanged[4] = {
  /* Index     EventStatusChanged              Referable Keys */
  /*     0 */ SetSecondaryDTC21F100_Oper ,  /* [PriEve4822E4_SecEve21F100] */
  /*     1 */ SetSecondaryDTC31F100_Oper ,  /* [PriEve4822E4_SecEve31F100] */
  /*     2 */ SetSecondaryDTC21F300_Oper ,  /* [PriEve4822F5_SecEve21F300] */
  /*     3 */ SetSecondaryDTC31F300_Oper    /* [PriEve4822F5_SecEve31F300] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventTable
  \details
  Element                              Description
  AgingCycleCounterThreshold           DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass, if AgingAllowedOfEventTable==FALSE we use '255' here, too.
  AgingCycleId                         DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  CallbackClearEventAllowedIdx         the index of the 0:1 relation pointing to Dem_Cfg_CallbackClearEventAllowed
  CombinedGroupsIdx                    the index of the 0:1 relation pointing to Dem_Cfg_CombinedGroups
  DtcTableIdx                          the index of the 1:1 relation pointing to Dem_Cfg_DtcTable
  EnableConditionGroupTableIdx         the index of the 1:1 relation pointing to Dem_Cfg_EnableConditionGroupTable
  EventDestination                     DemEventDestination of the DemEventParameter/DemEventClass
  EventFailureCycleCounterThreshold    DemEventFailureCycleCounterThreshold of the DemEventParameter/DemEventClass, '0': is also default for unset parameter
  EventKind                            DemEventKind of the DemEventParameter
  EventSignificance                    DemEventSignificance of the DemEventParameter/DemEventClass
  EventStatusChangedEndIdx             the end index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
  EventStatusChangedStartIdx           the start index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
  ExtendedDataTableIdx                 the index of the 1:1 relation pointing to Dem_Cfg_ExtendedDataTable
  FreezeFrameNumTableEndIdx            the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx          the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameTableStdFFIdx             the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable
  HealingTarget                        DemIndicatorHealingCycleCounterThreshold of the DemEventParameter/DemEventClass/DemIndicatorAttribute (for each event all attribute's value must be identical). Events without DemIndicatorAttribute have: 0.
  MaskedBits                           contains bitcoded the boolean data of Dem_Cfg_AgingAllowedOfEventTable, Dem_Cfg_CallbackClearEventAllowedUsedOfEventTable, Dem_Cfg_CombinedGroupsUsedOfEventTable, Dem_Cfg_EventLatchTFOfEventTable, Dem_Cfg_EventStatusChangedUsedOfEventTable, Dem_Cfg_FreezeFrameNumTableUsedOfEventTable, Dem_Cfg_NormalIndicatorTableUsedOfEventTable
  NormalIndicatorTableEndIdx           the end index of the 0:n relation pointing to Dem_Cfg_NormalIndicatorTable
  NormalIndicatorTableStartIdx         the start index of the 0:n relation pointing to Dem_Cfg_NormalIndicatorTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_EventTableType, DEM_CONST) Dem_Cfg_EventTable[60] = {
    /* Index    AgingCycleCounterThreshold  AgingCycleId                       CallbackClearEventAllowedIdx  CombinedGroupsIdx                         DtcTableIdx  EnableConditionGroupTableIdx  EventDestination            EventFailureCycleCounterThreshold  EventKind                                         EventSignificance                                                        EventStatusChangedEndIdx                         EventStatusChangedStartIdx                         ExtendedDataTableIdx  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  HealingTarget  MaskedBits  NormalIndicatorTableEndIdx                         NormalIndicatorTableStartIdx                               Referable Keys */
  { /*     0 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           1U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          1U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   2U,                                               2U,                                                 0U,                       3U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [#EVENT_INVALID, Satellite#0] */
  { /*     1 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           1U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          1U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   2U,                                               2U,                                                 0U,                       3U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [CodingEventNotCoded, Satellite#0] */
  { /*     2 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_CLM_SELFDIAG_FAILURE, Satellite#0] */
  { /*     3 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          2U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   4U,                                               2U,                                                 0U,                       5U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [CodingEventUnqualifiedData, Satellite#0] */
  { /*     4 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_CLOCK_FAILURE, Satellite#0] */
  { /*     5 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          3U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   3U,                                               2U,                                                 0U,                       4U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [CodingEventWrongVehicle, Satellite#0] */
  { /*     6 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_CVM_SELFDIAG_FAILURE, Satellite#0] */
  { /*     7 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          4U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                  11U,                                               2U,                                                 0U,                      12U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [DmTestAppl, Satellite#0] */
  { /*     8 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_ECM_SELFDIAG_FAILURE, Satellite#0] */
  { /*     9 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          5U,                           1U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                  14U,                                               2U,                                                 0U,                      15U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [DmTestCom, Satellite#0] */
  { /*    10 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_LOCKSTEP_SELFDIAG_FAILURE, Satellite#0] */
  { /*    11 */                         0U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          6U,                           1U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                  13U,                                               2U,                                                 0U,                      14U,            0U,      0x62U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FrsmEClusterSyncLoss, Satellite#0] */
  { /*    12 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  { /*    13 */                         0U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          7U,                           1U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                  12U,                                               2U,                                                 0U,                      13U,            0U,      0x62U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FrtrcvEFrBuserrorTrcv0, Satellite#0] */
  { /*    14 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_DATA_TX_TIMEOUT_FAILURE, Satellite#0] */
  { /*    15 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          8U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   8U,                                               2U,                                                 0U,                       9U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [GlobalOvervoltageExt, Satellite#0] */
  { /*    16 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_ECC_SELFTEST_FAILURE, Satellite#0] */
  { /*    17 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          9U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   7U,                                               2U,                                                 0U,                       8U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [GlobalOvervoltageInt, Satellite#0] */
  { /*    18 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_HARDWARE_ERROR, Satellite#0] */
  { /*    19 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         10U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                  10U,                                               2U,                                                 0U,                      11U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [GlobalUndervoltageExt, Satellite#0] */
  { /*    20 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_INT_INCONSISTENT, Satellite#0] */
  { /*    21 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         11U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   9U,                                               2U,                                                 0U,                      10U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [GlobalUndervoltageInt, Satellite#0] */
  { /*    22 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_LOOPBACK_SELFTEST_FAILURE, Satellite#0] */
  { /*    23 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         12U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   5U,                                               2U,                                                 0U,                       6U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [LocalOvervoltage, Satellite#0] */
  { /*    24 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SPI_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    25 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         13U,                           3U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   6U,                                               2U,                                                 0U,                       7U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [LocalUndervoltage, Satellite#0] */
  { /*    26 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDGM_E_IMPROPER_CALLER, Satellite#0] */
  { /*    27 */                       255U, DemConf_DemOperationCycle_NON_OBD,                           2U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         14U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                1U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1U,                                               2U,                                                 0U,                       2U,            0U,      0x22U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [VsmEventOpmode, Satellite#0] */
  { /*    28 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDGM_E_MONITORING, Satellite#0] */
  { /*    29 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDGM_E_SET_MODE, Satellite#0] */
  { /*    30 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  { /*    31 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [PORT_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    32 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDG_E_DISABLE_REJECTED, Satellite#0] */
  { /*    33 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDG_E_INT_INCONSISTENT, Satellite#0] */
  { /*    34 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDG_E_MODE_FAILED, Satellite#0] */
  { /*    35 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [WDG_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    36 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_COMPARE_FAILED, Satellite#0] */
  { /*    37 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_ERASE_FAILED, Satellite#0] */
  { /*    38 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_READ_FAILED, Satellite#0] */
  { /*    39 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_INT_INCONSISTENT, Satellite#0] */
  { /*    40 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    41 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_READ_FAILED_DED, Satellite#0] */
  { /*    42 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_HW_FAILURE, Satellite#0] */
  { /*    43 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_ECC_FAILED, Satellite#0] */
  { /*    44 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_UNEXPECTED_FLASH_ID, Satellite#0] */
  { /*    45 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [FLS_E_WRITE_FAILED, Satellite#0] */
  { /*    46 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [DIO_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    47 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*    48 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_INT_INCONSISTENT, Satellite#0] */
  { /*    49 */                       255U, /*no AgingCycle*/ 1U             ,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,          0U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x20U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [MCU_E_RESETCONTROLLER_STARTUP_FAILURE, Satellite#0] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                       CallbackClearEventAllowedIdx  CombinedGroupsIdx                         DtcTableIdx  EnableConditionGroupTableIdx  EventDestination            EventFailureCycleCounterThreshold  EventKind                                         EventSignificance                                                        EventStatusChangedEndIdx                         EventStatusChangedStartIdx                         ExtendedDataTableIdx  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  HealingTarget  MaskedBits  NormalIndicatorTableEndIdx                         NormalIndicatorTableStartIdx                               Referable Keys */
  { /*    50 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U,                                       0U,         15U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              1U,                                                0U,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            3U,      0x75U,                                                1U,                                                  0U },  /* [PriEve4822E4_SecEve21F100, Satellite#0] */
  { /*    51 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U,                                       0U,         15U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              2U,                                                1U,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            3U,      0x75U,                                                1U,                                                  0U },  /* [PriEve4822E4_SecEve31F100, Satellite#0] */
  { /*    52 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U,                                       1U,         16U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              3U,                                                2U,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            3U,      0x75U,                                                1U,                                                  0U },  /* [PriEve4822F5_SecEve21F300, Satellite#0] */
  { /*    53 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U,                                       1U,         16U,                           0U, DEM_CFG_MEMORYID_PRIMARY  ,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              4U,                                                3U,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            3U,      0x75U,                                                1U,                                                  0U },  /* [PriEve4822F5_SecEve31F300, Satellite#0] */
  { /*    54 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         17U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SecondaryEve_21F300, Satellite#0] */
  { /*    55 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         18U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SecondaryEve_30F300, Satellite#0] */
  { /*    56 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         19U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SecondaryEve_31F100, Satellite#0] */
  { /*    57 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         20U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SecondaryEve_31F300, Satellite#0] */
  { /*    58 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         21U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE },  /* [SecondaryEve_21F100, Satellite#0] */
  { /*    59 */                        64U, DemConf_DemOperationCycle_NON_OBD,                           0U, DEM_CFG_NO_COMBINEDGROUPSIDXOFEVENTTABLE,         22U,                           0U, DEM_CFG_MEMORYID_SECONDARY,                                0U, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0U, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0U,            0U,      0x60U, DEM_CFG_NO_NORMALINDICATORTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_NORMALINDICATORTABLESTARTIDXOFEVENTTABLE }   /* [SecondaryEve_20F300, Satellite#0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataTable
  \details
  Element                                   Description
  DataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  MaxRecordSize                         
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[15] = {
    /* Index    DataCollectionTableEdr2CollIndEndIdx                                DataCollectionTableEdr2CollIndStartIdx                                MaxRecordSize        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE,            0U },  /* [#NoExtendedDataRecordConfigured, MCU_E_CLM_SELFDIAG_FAILURE, MCU_E_CLOCK_FAILURE, MCU_E_CVM_SELFDIAG_FAILURE, MCU_E_ECM_SELFDIAG_FAILURE, MCU_E_LOCKSTEP_SELFDIAG_FAILURE, MCU_E_WRITE_TIMEOUT_FAILURE, SPI_E_DATA_TX_TIMEOUT_FAILURE, SPI_E_ECC_SELFTEST_FAILURE, SPI_E_HARDWARE_ERROR, SPI_E_INT_INCONSISTENT, SPI_E_LOOPBACK_SELFTEST_FAILURE, SPI_E_REG_WRITE_VERIFY, WDGM_E_IMPROPER_CALLER, WDGM_E_MONITORING, WDGM_E_SET_MODE, PORT_E_WRITE_TIMEOUT_FAILURE, PORT_E_REG_WRITE_VERIFY, WDG_E_DISABLE_REJECTED, WDG_E_INT_INCONSISTENT, WDG_E_MODE_FAILED, WDG_E_REG_WRITE_VERIFY, FLS_E_COMPARE_FAILED, FLS_E_ERASE_FAILED, FLS_E_READ_FAILED, FLS_E_INT_INCONSISTENT, FLS_E_REG_WRITE_VERIFY, FLS_E_READ_FAILED_DED, FLS_E_HW_FAILURE, FLS_E_ECC_FAILED, FLS_E_UNEXPECTED_FLASH_ID, FLS_E_WRITE_FAILED, DIO_E_REG_WRITE_VERIFY, MCU_E_REG_WRITE_VERIFY, MCU_E_INT_INCONSISTENT, MCU_E_RESETCONTROLLER_STARTUP_FAILURE, PriEve4822E4_SecEve21F100, PriEve4822E4_SecEve31F100, PriEve4822F5_SecEve21F300, PriEve4822F5_SecEve31F300, SecondaryEve_21F300, SecondaryEve_30F300, SecondaryEve_31F100, SecondaryEve_31F300, SecondaryEve_21F100, SecondaryEve_20F300] */
  { /*     1 */                                                                 2U,                                                                   0U,            1U },  /* [#ExtendedDataClass_DTC_023000_Props, VsmEventOpmode] */
  { /*     2 */                                                                 4U,                                                                   2U,            1U },  /* [#ExtendedDataClass_DTC_023008_Props, #EVENT_INVALID, CodingEventNotCoded] */
  { /*     3 */                                                                 6U,                                                                   4U,            1U },  /* [#ExtendedDataClass_DTC_023009_Props, CodingEventWrongVehicle] */
  { /*     4 */                                                                 8U,                                                                   6U,            1U },  /* [#ExtendedDataClass_DTC_02300A_Props, CodingEventUnqualifiedData] */
  { /*     5 */                                                                10U,                                                                   8U,            1U },  /* [#ExtendedDataClass_DTC_023040_Props, LocalOvervoltage] */
  { /*     6 */                                                                12U,                                                                  10U,            1U },  /* [#ExtendedDataClass_DTC_023041_Props, LocalUndervoltage] */
  { /*     7 */                                                                14U,                                                                  12U,            1U },  /* [#ExtendedDataClass_DTC_023042_Props, GlobalOvervoltageInt] */
  { /*     8 */                                                                16U,                                                                  14U,            1U },  /* [#ExtendedDataClass_DTC_023043_Props, GlobalOvervoltageExt] */
  { /*     9 */                                                                18U,                                                                  16U,            1U },  /* [#ExtendedDataClass_DTC_023044_Props, GlobalUndervoltageInt] */
  { /*    10 */                                                                20U,                                                                  18U,            1U },  /* [#ExtendedDataClass_DTC_023045_Props, GlobalUndervoltageExt] */
  { /*    11 */                                                                22U,                                                                  20U,            1U },  /* [#ExtendedDataClass_DTC_02FF30_Props, DmTestAppl] */
  { /*    12 */                                                                25U,                                                                  22U,            1U },  /* [#ExtendedDataClass_DTC_D5041F_Props, FrtrcvEFrBuserrorTrcv0] */
  { /*    13 */                                                                28U,                                                                  25U,            1U },  /* [#ExtendedDataClass_DTC_D50420_Props, FrsmEClusterSyncLoss] */
  { /*    14 */                                                                30U,                                                                  28U,            1U }   /* [#ExtendedDataClass_DTC_D50BFF_Props, DmTestCom] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameNumTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameNumTable
  \details
  Element     Description
  FFUpdate
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameNumTableType, DEM_CONST) Dem_Cfg_FreezeFrameNumTable[2] = {
    /* Index    FFUpdate        Referable Keys */
  { /*     0 */    FALSE },  /* [calcFFRecNumClass_02, #EVENT_INVALID, CodingEventNotCoded, CodingEventUnqualifiedData, CodingEventWrongVehicle, DmTestAppl, DmTestCom, FrsmEClusterSyncLoss, FrtrcvEFrBuserrorTrcv0, GlobalOvervoltageExt, GlobalOvervoltageInt, GlobalUndervoltageExt, GlobalUndervoltageInt, LocalOvervoltage, LocalUndervoltage, VsmEventOpmode] */
  { /*     1 */     TRUE }   /* [calcFFRecNumClass_02, #EVENT_INVALID, CodingEventNotCoded, CodingEventUnqualifiedData, CodingEventWrongVehicle, DmTestAppl, DmTestCom, FrsmEClusterSyncLoss, FrtrcvEFrBuserrorTrcv0, GlobalOvervoltageExt, GlobalOvervoltageInt, GlobalUndervoltageExt, GlobalUndervoltageInt, LocalOvervoltage, LocalUndervoltage, VsmEventOpmode] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameTable
  \details
  Element                                   Description
  DataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  RecordSize                                Summarized size of did data that is stored in Dem_Cfg_PrimaryEntryType.SnapshotData[][] (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                             Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[16] = {
    /* Index    DataCollectionTableFfm2CollIndEndIdx                               DataCollectionTableFfm2CollIndStartIdx                               RecordSize  RecordSizeUds        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0U,            0U },  /* [#NoFreezeFrameConfigured, MCU_E_CLM_SELFDIAG_FAILURE, MCU_E_CLOCK_FAILURE, MCU_E_CVM_SELFDIAG_FAILURE, MCU_E_ECM_SELFDIAG_FAILURE, MCU_E_LOCKSTEP_SELFDIAG_FAILURE, MCU_E_WRITE_TIMEOUT_FAILURE, SPI_E_DATA_TX_TIMEOUT_FAILURE, SPI_E_ECC_SELFTEST_FAILURE, SPI_E_HARDWARE_ERROR, SPI_E_INT_INCONSISTENT, SPI_E_LOOPBACK_SELFTEST_FAILURE, SPI_E_REG_WRITE_VERIFY, WDGM_E_IMPROPER_CALLER, WDGM_E_MONITORING, WDGM_E_SET_MODE, PORT_E_WRITE_TIMEOUT_FAILURE, PORT_E_REG_WRITE_VERIFY, WDG_E_DISABLE_REJECTED, WDG_E_INT_INCONSISTENT, WDG_E_MODE_FAILED, WDG_E_REG_WRITE_VERIFY, FLS_E_COMPARE_FAILED, FLS_E_ERASE_FAILED, FLS_E_READ_FAILED, FLS_E_INT_INCONSISTENT, FLS_E_REG_WRITE_VERIFY, FLS_E_READ_FAILED_DED, FLS_E_HW_FAILURE, FLS_E_ECC_FAILED, FLS_E_UNEXPECTED_FLASH_ID, FLS_E_WRITE_FAILED, DIO_E_REG_WRITE_VERIFY, MCU_E_REG_WRITE_VERIFY, MCU_E_INT_INCONSISTENT, MCU_E_RESETCONTROLLER_STARTUP_FAILURE, PriEve4822E4_SecEve21F100, PriEve4822E4_SecEve31F100, PriEve4822F5_SecEve21F300, PriEve4822F5_SecEve31F300, SecondaryEve_21F300, SecondaryEve_30F300, SecondaryEve_31F100, SecondaryEve_31F300, SecondaryEve_21F100, SecondaryEve_20F300] */
  { /*     1 */                                                               11U,                                                                  0U,        23U,           47U },  /* [#DemFreezeFrameClass_Systemzeit] */
  { /*     2 */                                                               21U,                                                                 11U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023000_Props, VsmEventOpmode] */
  { /*     3 */                                                               31U,                                                                 21U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023008_Props, #EVENT_INVALID, CodingEventNotCoded] */
  { /*     4 */                                                               41U,                                                                 31U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023009_Props, CodingEventWrongVehicle] */
  { /*     5 */                                                               51U,                                                                 41U,        19U,           41U },  /* [#FreezeFrameClass_DTC_02300A_Props, CodingEventUnqualifiedData] */
  { /*     6 */                                                               61U,                                                                 51U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023040_Props, LocalOvervoltage] */
  { /*     7 */                                                               71U,                                                                 61U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023041_Props, LocalUndervoltage] */
  { /*     8 */                                                               81U,                                                                 71U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023042_Props, GlobalOvervoltageInt] */
  { /*     9 */                                                               91U,                                                                 81U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023043_Props, GlobalOvervoltageExt] */
  { /*    10 */                                                              101U,                                                                 91U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023044_Props, GlobalUndervoltageInt] */
  { /*    11 */                                                              111U,                                                                101U,        19U,           41U },  /* [#FreezeFrameClass_DTC_023045_Props, GlobalUndervoltageExt] */
  { /*    12 */                                                              121U,                                                                111U,        19U,           41U },  /* [#FreezeFrameClass_DTC_02FF30_Props, DmTestAppl] */
  { /*    13 */                                                              131U,                                                                121U,        19U,           41U },  /* [#FreezeFrameClass_DTC_D5041F_Props, FrtrcvEFrBuserrorTrcv0] */
  { /*    14 */                                                              141U,                                                                131U,        19U,           41U },  /* [#FreezeFrameClass_DTC_D50420_Props, FrsmEClusterSyncLoss] */
  { /*    15 */                                                              148U,                                                                141U,        16U,           32U }   /* [#FreezeFrameClass_DTC_D50BFF_Props, DmTestCom] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 8 * Primary, 24 * Secondary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_MemoryBlockIdType, DEM_CONST) Dem_Cfg_MemoryBlockId[34] = {
  /* Index     MemoryBlockId                                                             Referable Keys */
  /*     0 */ NvMConf_NvMBlockDescriptor_DemAdminDataBlock /*NvMBlockId=2*/        ,  /* [Dem_AdminData] */
  /*     1 */ NvMConf_NvMBlockDescriptor_DemStatusDataBlock /*NvMBlockId=59*/      ,  /* [Dem_StatusData] */
  /*     2 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 /*NvMBlockId=60*/    ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 /*NvMBlockId=61*/    ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 /*NvMBlockId=62*/    ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 /*NvMBlockId=63*/    ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 /*NvMBlockId=64*/    ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 /*NvMBlockId=65*/    ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 /*NvMBlockId=66*/    ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 /*NvMBlockId=67*/    ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock0 /*NvMBlockId=68*/  ,  /* [Dem_SecondaryEntry0] */
  /*    11 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock1 /*NvMBlockId=69*/  ,  /* [Dem_SecondaryEntry1] */
  /*    12 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock2 /*NvMBlockId=70*/  ,  /* [Dem_SecondaryEntry2] */
  /*    13 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock3 /*NvMBlockId=71*/  ,  /* [Dem_SecondaryEntry3] */
  /*    14 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock4 /*NvMBlockId=72*/  ,  /* [Dem_SecondaryEntry4] */
  /*    15 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock5 /*NvMBlockId=73*/  ,  /* [Dem_SecondaryEntry5] */
  /*    16 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock6 /*NvMBlockId=74*/  ,  /* [Dem_SecondaryEntry6] */
  /*    17 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock7 /*NvMBlockId=75*/  ,  /* [Dem_SecondaryEntry7] */
  /*    18 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock8 /*NvMBlockId=76*/  ,  /* [Dem_SecondaryEntry8] */
  /*    19 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock9 /*NvMBlockId=77*/  ,  /* [Dem_SecondaryEntry9] */
  /*    20 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock10 /*NvMBlockId=78*/ ,  /* [Dem_SecondaryEntry10] */
  /*    21 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock11 /*NvMBlockId=79*/ ,  /* [Dem_SecondaryEntry11] */
  /*    22 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock12 /*NvMBlockId=80*/ ,  /* [Dem_SecondaryEntry12] */
  /*    23 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock13 /*NvMBlockId=81*/ ,  /* [Dem_SecondaryEntry13] */
  /*    24 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock14 /*NvMBlockId=82*/ ,  /* [Dem_SecondaryEntry14] */
  /*    25 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock15 /*NvMBlockId=83*/ ,  /* [Dem_SecondaryEntry15] */
  /*    26 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock16 /*NvMBlockId=84*/ ,  /* [Dem_SecondaryEntry16] */
  /*    27 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock17 /*NvMBlockId=85*/ ,  /* [Dem_SecondaryEntry17] */
  /*    28 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock18 /*NvMBlockId=86*/ ,  /* [Dem_SecondaryEntry18] */
  /*    29 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock19 /*NvMBlockId=87*/ ,  /* [Dem_SecondaryEntry19] */
  /*    30 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock20 /*NvMBlockId=88*/ ,  /* [Dem_SecondaryEntry20] */
  /*    31 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock21 /*NvMBlockId=89*/ ,  /* [Dem_SecondaryEntry21] */
  /*    32 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock22 /*NvMBlockId=90*/ ,  /* [Dem_SecondaryEntry22] */
  /*    33 */ NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock23 /*NvMBlockId=91*/    /* [Dem_SecondaryEntry23] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 8 * Primary, 24 * Secondary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_MemoryDataPtr[34] = {
  /* Index     MemoryDataPtr                                                                                     Referable Keys */
  /*     0 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAdminData()           /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_AdminData] */
  /*     1 */ (Dem_NvDataPtrType) &Dem_Cfg_GetStatusData()          /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_StatusData] */
  /*     2 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_0()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry0] */
  /*    11 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_1()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry1] */
  /*    12 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_2()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry2] */
  /*    13 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_3()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry3] */
  /*    14 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_4()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry4] */
  /*    15 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_5()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry5] */
  /*    16 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_6()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry6] */
  /*    17 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_7()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry7] */
  /*    18 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_8()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry8] */
  /*    19 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_9()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry9] */
  /*    20 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_10()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry10] */
  /*    21 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_11()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry11] */
  /*    22 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_12()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry12] */
  /*    23 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_13()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry13] */
  /*    24 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_14()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry14] */
  /*    25 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_15()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry15] */
  /*    26 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_16()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry16] */
  /*    27 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_17()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry17] */
  /*    28 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_18()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry18] */
  /*    29 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_19()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry19] */
  /*    30 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_20()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry20] */
  /*    31 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_21()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry21] */
  /*    32 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_22()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry22] */
  /*    33 */ (Dem_NvDataPtrType) &Dem_Cfg_GetSecondaryEntry_23()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_SecondaryEntry23] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataSize
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataSize
  \brief  The array contains these items: Admin, Status, 8 * Primary, 24 * Secondary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_MemoryDataSizeType, DEM_CONST) Dem_Cfg_MemoryDataSize[34] = {
  /* Index     MemoryDataSize                                                           Referable Keys */
  /*     0 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetAdminData())         ,  /* [Dem_AdminData] */
  /*     1 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetStatusData())        ,  /* [Dem_StatusData] */
  /*     2 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_0())    ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_1())    ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_2())    ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_3())    ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_4())    ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_5())    ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_6())    ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_7())    ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_0())  ,  /* [Dem_SecondaryEntry0] */
  /*    11 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_1())  ,  /* [Dem_SecondaryEntry1] */
  /*    12 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_2())  ,  /* [Dem_SecondaryEntry2] */
  /*    13 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_3())  ,  /* [Dem_SecondaryEntry3] */
  /*    14 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_4())  ,  /* [Dem_SecondaryEntry4] */
  /*    15 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_5())  ,  /* [Dem_SecondaryEntry5] */
  /*    16 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_6())  ,  /* [Dem_SecondaryEntry6] */
  /*    17 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_7())  ,  /* [Dem_SecondaryEntry7] */
  /*    18 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_8())  ,  /* [Dem_SecondaryEntry8] */
  /*    19 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_9())  ,  /* [Dem_SecondaryEntry9] */
  /*    20 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_10()) ,  /* [Dem_SecondaryEntry10] */
  /*    21 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_11()) ,  /* [Dem_SecondaryEntry11] */
  /*    22 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_12()) ,  /* [Dem_SecondaryEntry12] */
  /*    23 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_13()) ,  /* [Dem_SecondaryEntry13] */
  /*    24 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_14()) ,  /* [Dem_SecondaryEntry14] */
  /*    25 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_15()) ,  /* [Dem_SecondaryEntry15] */
  /*    26 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_16()) ,  /* [Dem_SecondaryEntry16] */
  /*    27 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_17()) ,  /* [Dem_SecondaryEntry17] */
  /*    28 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_18()) ,  /* [Dem_SecondaryEntry18] */
  /*    29 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_19()) ,  /* [Dem_SecondaryEntry19] */
  /*    30 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_20()) ,  /* [Dem_SecondaryEntry20] */
  /*    31 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_21()) ,  /* [Dem_SecondaryEntry21] */
  /*    32 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_22()) ,  /* [Dem_SecondaryEntry22] */
  /*    33 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetSecondaryEntry_23())    /* [Dem_SecondaryEntry23] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntry
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryEntry
  \brief  The array contains these items: 8 * Primary, 24 * Secondary, 3 * ReadoutBuffer; size = DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE + DEM_CFG_NUMBER_OF_READOUTBUFFERS
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_SharedDataPtrType, DEM_CONST) Dem_Cfg_MemoryEntry[35] = {
  /* Index     MemoryEntry                                                                                             Referable Keys */
  /*     0 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     1 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     2 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     3 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     4 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     5 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     6 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     7 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*     8 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_0()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry0] */
  /*     9 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_1()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry1] */
  /*    10 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_2()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry2] */
  /*    11 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_3()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry3] */
  /*    12 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_4()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry4] */
  /*    13 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_5()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry5] */
  /*    14 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_6()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry6] */
  /*    15 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_7()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry7] */
  /*    16 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_8()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry8] */
  /*    17 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_9()      /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry9] */
  /*    18 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_10()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry10] */
  /*    19 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_11()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry11] */
  /*    20 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_12()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry12] */
  /*    21 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_13()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry13] */
  /*    22 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_14()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry14] */
  /*    23 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_15()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry15] */
  /*    24 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_16()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry16] */
  /*    25 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_17()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry17] */
  /*    26 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_18()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry18] */
  /*    27 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_19()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry19] */
  /*    28 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_20()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry20] */
  /*    29 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_21()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry21] */
  /*    30 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_22()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry22] */
  /*    31 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetSecondaryEntry_23()     /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_SecondaryEntry23] */
  /*    32 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetReadoutBuffer(0).Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_Cfg_ReadoutBuffer[0].Data] */
  /*    33 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetReadoutBuffer(1).Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_Cfg_ReadoutBuffer[1].Data] */
  /*    34 */ (Dem_SharedDataPtrType) &Dem_Cfg_GetReadoutBuffer(2).Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_Cfg_ReadoutBuffer[2].Data] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_MemoryEntryInit = { 0 };
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_TimeSeriesEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_TimeSeriesEntryType, DEM_CONST) Dem_Cfg_TimeSeriesEntryInit = { 0 };
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_AdminData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDTCTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDTCTable
  \brief  size = DEM_CFG_NUMBER_OF_CLEARDTCS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_ClearDTC_DataType, DEM_VAR_NOINIT) Dem_Cfg_ClearDTCTable[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CombinedGroupInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CombinedGroupInternalStatus
  \brief  size = DEM_CFG_GLOBAL_COMBINED_GROUP_COUNT
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_CombinedGroupInternalStatusUType, DEM_VAR_NOINIT) Dem_Cfg_CombinedGroupInternalStatus;  /* PRQA S 0759 */  /* MD_CSL_18.4 */  /* index: combinedGroupIndex */
  /* Index        Referable Keys  */
  /*     0 */  /* [CEG_Primary_DTC_4822E4] */
  /*     1 */  /* [CEG_Primary_DTC_4822F5] */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CombinedGroupStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CombinedGroupStatus
  \brief  size = DEM_CFG_GLOBAL_COMBINED_GROUP_COUNT
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_CombinedGroupStatusUType, DEM_VAR_NOINIT) Dem_Cfg_CombinedGroupStatus;  /* PRQA S 0759 */  /* MD_CSL_18.4 */  /* index: combinedGroupIndex */
  /* Index        Referable Keys  */
  /*     0 */  /* [CEG_Primary_DTC_4822E4] */
  /*     1 */  /* [CEG_Primary_DTC_4822F5] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_Cfg_CommitBuffer;  /* PRQA S 0759 */ /* MD_MSR_18.4 */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DTCSelectorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DTCSelectorTable
  \brief  size = DEM_CFG_NUMBER_OF_DTCSELECTORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_DTCSelector_DataType, DEM_VAR_NOINIT) Dem_Cfg_DTCSelectorTable[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupCounter
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupCounter[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#DEM_CONDITION_GROUP_ComErrorLock, __Internal_ControlDtcSetting, DemEnableCondition_StdDiag, DemEnableCondition_Stm] */
  /*     2 */  /* [#DEM_CONDITION_GROUP_ComErrorLockFlAsTr, __Internal_ControlDtcSetting, DemEnableCondition_Omc, DemEnableCondition_StdDiag, DemEnableCondition_Stm] */
  /*     3 */  /* [#DEM_CONDITION_GROUP_DefaultErrorLock, __Internal_ControlDtcSetting, DemEnableCondition_StdDiag] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupState[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#DEM_CONDITION_GROUP_ComErrorLock, __Internal_ControlDtcSetting, DemEnableCondition_StdDiag, DemEnableCondition_Stm] */
  /*     2 */  /* [#DEM_CONDITION_GROUP_ComErrorLockFlAsTr, __Internal_ControlDtcSetting, DemEnableCondition_Omc, DemEnableCondition_StdDiag, DemEnableCondition_Stm] */
  /*     3 */  /* [#DEM_CONDITION_GROUP_DefaultErrorLock, __Internal_ControlDtcSetting, DemEnableCondition_StdDiag] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition ID. Table value: current condition state '0' disable, '1' enable.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionStateType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionState[4];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDebounceValue
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDebounceValueType, DEM_VAR_NOINIT) Dem_Cfg_EventDebounceValue[60];
  /* Index        Referable Keys  */
  /*     0 */  /* [#EVENT_INVALID, Satellite#0] */
  /*     1 */  /* [CodingEventNotCoded, Satellite#0] */
  /*     2 */  /* [MCU_E_CLM_SELFDIAG_FAILURE, Satellite#0] */
  /*     3 */  /* [CodingEventUnqualifiedData, Satellite#0] */
  /*     4 */  /* [MCU_E_CLOCK_FAILURE, Satellite#0] */
  /*     5 */  /* [CodingEventWrongVehicle, Satellite#0] */
  /*     6 */  /* [MCU_E_CVM_SELFDIAG_FAILURE, Satellite#0] */
  /*     7 */  /* [DmTestAppl, Satellite#0] */
  /*     8 */  /* [MCU_E_ECM_SELFDIAG_FAILURE, Satellite#0] */
  /*     9 */  /* [DmTestCom, Satellite#0] */
  /*    10 */  /* [MCU_E_LOCKSTEP_SELFDIAG_FAILURE, Satellite#0] */
  /*    11 */  /* [FrsmEClusterSyncLoss, Satellite#0] */
  /*    12 */  /* [MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*    13 */  /* [FrtrcvEFrBuserrorTrcv0, Satellite#0] */
  /*    14 */  /* [SPI_E_DATA_TX_TIMEOUT_FAILURE, Satellite#0] */
  /*    15 */  /* [GlobalOvervoltageExt, Satellite#0] */
  /*    16 */  /* [SPI_E_ECC_SELFTEST_FAILURE, Satellite#0] */
  /*    17 */  /* [GlobalOvervoltageInt, Satellite#0] */
  /*    18 */  /* [SPI_E_HARDWARE_ERROR, Satellite#0] */
  /*    19 */  /* [GlobalUndervoltageExt, Satellite#0] */
  /*    20 */  /* [SPI_E_INT_INCONSISTENT, Satellite#0] */
  /*    21 */  /* [GlobalUndervoltageInt, Satellite#0] */
  /*    22 */  /* [SPI_E_LOOPBACK_SELFTEST_FAILURE, Satellite#0] */
  /*    23 */  /* [LocalOvervoltage, Satellite#0] */
  /*    24 */  /* [SPI_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    25 */  /* [LocalUndervoltage, Satellite#0] */
  /*    26 */  /* [WDGM_E_IMPROPER_CALLER, Satellite#0] */
  /*    27 */  /* [VsmEventOpmode, Satellite#0] */
  /*    28 */  /* [WDGM_E_MONITORING, Satellite#0] */
  /*    29 */  /* [WDGM_E_SET_MODE, Satellite#0] */
  /*    30 */  /* [PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*    31 */  /* [PORT_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    32 */  /* [WDG_E_DISABLE_REJECTED, Satellite#0] */
  /*    33 */  /* [WDG_E_INT_INCONSISTENT, Satellite#0] */
  /*    34 */  /* [WDG_E_MODE_FAILED, Satellite#0] */
  /*    35 */  /* [WDG_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    36 */  /* [FLS_E_COMPARE_FAILED, Satellite#0] */
  /*    37 */  /* [FLS_E_ERASE_FAILED, Satellite#0] */
  /*    38 */  /* [FLS_E_READ_FAILED, Satellite#0] */
  /*    39 */  /* [FLS_E_INT_INCONSISTENT, Satellite#0] */
  /*    40 */  /* [FLS_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    41 */  /* [FLS_E_READ_FAILED_DED, Satellite#0] */
  /*    42 */  /* [FLS_E_HW_FAILURE, Satellite#0] */
  /*    43 */  /* [FLS_E_ECC_FAILED, Satellite#0] */
  /*    44 */  /* [FLS_E_UNEXPECTED_FLASH_ID, Satellite#0] */
  /*    45 */  /* [FLS_E_WRITE_FAILED, Satellite#0] */
  /*    46 */  /* [DIO_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    47 */  /* [MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    48 */  /* [MCU_E_INT_INCONSISTENT, Satellite#0] */
  /*    49 */  /* [MCU_E_RESETCONTROLLER_STARTUP_FAILURE, Satellite#0] */
  /* Index        Referable Keys  */
  /*    50 */  /* [PriEve4822E4_SecEve21F100, Satellite#0] */
  /*    51 */  /* [PriEve4822E4_SecEve31F100, Satellite#0] */
  /*    52 */  /* [PriEve4822F5_SecEve21F300, Satellite#0] */
  /*    53 */  /* [PriEve4822F5_SecEve31F300, Satellite#0] */
  /*    54 */  /* [SecondaryEve_21F300, Satellite#0] */
  /*    55 */  /* [SecondaryEve_30F300, Satellite#0] */
  /*    56 */  /* [SecondaryEve_31F100, Satellite#0] */
  /*    57 */  /* [SecondaryEve_31F300, Satellite#0] */
  /*    58 */  /* [SecondaryEve_21F100, Satellite#0] */
  /*    59 */  /* [SecondaryEve_20F300, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_NOINIT) Dem_Cfg_EventInternalStatus[60];
  /* Index        Referable Keys  */
  /*     0 */  /* [#EVENT_INVALID, Satellite#0] */
  /*     1 */  /* [CodingEventNotCoded, Satellite#0] */
  /*     2 */  /* [MCU_E_CLM_SELFDIAG_FAILURE, Satellite#0] */
  /*     3 */  /* [CodingEventUnqualifiedData, Satellite#0] */
  /*     4 */  /* [MCU_E_CLOCK_FAILURE, Satellite#0] */
  /*     5 */  /* [CodingEventWrongVehicle, Satellite#0] */
  /*     6 */  /* [MCU_E_CVM_SELFDIAG_FAILURE, Satellite#0] */
  /*     7 */  /* [DmTestAppl, Satellite#0] */
  /*     8 */  /* [MCU_E_ECM_SELFDIAG_FAILURE, Satellite#0] */
  /*     9 */  /* [DmTestCom, Satellite#0] */
  /*    10 */  /* [MCU_E_LOCKSTEP_SELFDIAG_FAILURE, Satellite#0] */
  /*    11 */  /* [FrsmEClusterSyncLoss, Satellite#0] */
  /*    12 */  /* [MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*    13 */  /* [FrtrcvEFrBuserrorTrcv0, Satellite#0] */
  /*    14 */  /* [SPI_E_DATA_TX_TIMEOUT_FAILURE, Satellite#0] */
  /*    15 */  /* [GlobalOvervoltageExt, Satellite#0] */
  /*    16 */  /* [SPI_E_ECC_SELFTEST_FAILURE, Satellite#0] */
  /*    17 */  /* [GlobalOvervoltageInt, Satellite#0] */
  /*    18 */  /* [SPI_E_HARDWARE_ERROR, Satellite#0] */
  /*    19 */  /* [GlobalUndervoltageExt, Satellite#0] */
  /*    20 */  /* [SPI_E_INT_INCONSISTENT, Satellite#0] */
  /*    21 */  /* [GlobalUndervoltageInt, Satellite#0] */
  /*    22 */  /* [SPI_E_LOOPBACK_SELFTEST_FAILURE, Satellite#0] */
  /*    23 */  /* [LocalOvervoltage, Satellite#0] */
  /*    24 */  /* [SPI_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    25 */  /* [LocalUndervoltage, Satellite#0] */
  /*    26 */  /* [WDGM_E_IMPROPER_CALLER, Satellite#0] */
  /*    27 */  /* [VsmEventOpmode, Satellite#0] */
  /*    28 */  /* [WDGM_E_MONITORING, Satellite#0] */
  /*    29 */  /* [WDGM_E_SET_MODE, Satellite#0] */
  /*    30 */  /* [PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*    31 */  /* [PORT_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    32 */  /* [WDG_E_DISABLE_REJECTED, Satellite#0] */
  /*    33 */  /* [WDG_E_INT_INCONSISTENT, Satellite#0] */
  /*    34 */  /* [WDG_E_MODE_FAILED, Satellite#0] */
  /*    35 */  /* [WDG_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    36 */  /* [FLS_E_COMPARE_FAILED, Satellite#0] */
  /*    37 */  /* [FLS_E_ERASE_FAILED, Satellite#0] */
  /*    38 */  /* [FLS_E_READ_FAILED, Satellite#0] */
  /*    39 */  /* [FLS_E_INT_INCONSISTENT, Satellite#0] */
  /*    40 */  /* [FLS_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    41 */  /* [FLS_E_READ_FAILED_DED, Satellite#0] */
  /*    42 */  /* [FLS_E_HW_FAILURE, Satellite#0] */
  /*    43 */  /* [FLS_E_ECC_FAILED, Satellite#0] */
  /*    44 */  /* [FLS_E_UNEXPECTED_FLASH_ID, Satellite#0] */
  /*    45 */  /* [FLS_E_WRITE_FAILED, Satellite#0] */
  /*    46 */  /* [DIO_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    47 */  /* [MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  /*    48 */  /* [MCU_E_INT_INCONSISTENT, Satellite#0] */
  /*    49 */  /* [MCU_E_RESETCONTROLLER_STARTUP_FAILURE, Satellite#0] */
  /* Index        Referable Keys  */
  /*    50 */  /* [PriEve4822E4_SecEve21F100, Satellite#0] */
  /*    51 */  /* [PriEve4822E4_SecEve31F100, Satellite#0] */
  /*    52 */  /* [PriEve4822F5_SecEve21F300, Satellite#0] */
  /*    53 */  /* [PriEve4822F5_SecEve31F300, Satellite#0] */
  /*    54 */  /* [SecondaryEve_21F300, Satellite#0] */
  /*    55 */  /* [SecondaryEve_30F300, Satellite#0] */
  /*    56 */  /* [SecondaryEve_31F100, Satellite#0] */
  /*    57 */  /* [SecondaryEve_31F300, Satellite#0] */
  /*    58 */  /* [SecondaryEve_21F100, Satellite#0] */
  /*    59 */  /* [SecondaryEve_20F300, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventQueue
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventQueue
  \brief  size = DEM_CFG_BSW_ERROR_BUFFER_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_EventQueueType, DEM_VAR_NOINIT) Dem_Cfg_EventQueue[25];
#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterInfoTable
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_FilterData_InfoType, DEM_VAR_NOINIT) Dem_Cfg_FilterInfoTable[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterReportedEvents
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterReportedEvents
  \brief  size = ceiling( DEM_G_NUMBER_OF_EVENTS / 8 )
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_FilterReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_FilterReportedEvents[8];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameIteratorTable
  \brief  size = DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_FreezeFrameIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_FreezeFrameIteratorTable[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_IndicatorBlinking
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_IndicatorBlinking
  \brief  size = DEM_G_NUMBER_OF_INDICATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_IndicatorBlinkingType, DEM_VAR_NOINIT) Dem_Cfg_IndicatorBlinking[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_IndicatorContinuous
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_IndicatorContinuous
  \brief  size = DEM_G_NUMBER_OF_INDICATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_IndicatorContinuousType, DEM_VAR_NOINIT) Dem_Cfg_IndicatorContinuous[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryCommitNumber
  \brief  The array contains these items: Admin, Status, 8 * Primary, 24 * Secondary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Cfg_MemoryCommitNumberType, DEM_VAR_NOINIT) Dem_Cfg_MemoryCommitNumber[34];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryStatus
  \brief  The array contains these items: Admin, Status, 8 * Primary, 24 * Secondary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_NOINIT) Dem_Cfg_MemoryStatus[34];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_PrimaryChronology
  \brief  size = DEM_CFG_GLOBAL_PRIMARY_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_Cfg_PrimaryChronology[8];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_0;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_1;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_2;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_3;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_4;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_5;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_6;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_7;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_NOINIT) Dem_Cfg_ReadoutBuffer[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReportedEventsOfFilter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ReportedEventsOfFilter
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_ReportedEventsOfFilter[3];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SatelliteInfo0
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SatelliteInfo0
  \brief  Buffer for satellite data on OsApplication "0"
*/ 
#define DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_SatelliteInfoType0, DEM_VAR_NOINIT) Dem_Cfg_SatelliteInfo0;
#define DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SecondaryChronology
  \brief  size = DEM_CFG_GLOBAL_SECONDARY_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_Cfg_SecondaryChronology[24];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_0;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_1;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_10
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_10;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_11
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_11;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_12
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_12;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_13
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_13;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_14
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_14;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_15
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_15;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_16
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_16;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_17
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_17;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_18
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_18;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_19
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_19;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_2;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_20
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_20;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_21
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_21;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_22
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_22;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_23
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_23;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_3;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_4;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_5;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_6;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_7;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_8;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SecondaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_SecondaryEntry_9;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StatusData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_StatusData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Bmw (Vector), VARIANT-PRE-COMPILE, 11.06.02.92975]
**********************************************************************************************************************/

