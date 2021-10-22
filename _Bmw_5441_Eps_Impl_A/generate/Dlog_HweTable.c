/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Hardware Description Data.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.3.1
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.954083
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include <Std_Types.h>
#include "Dlog_HweTable.h"
#include "DlogClassic_Cfg.h"
#include "Dlog_PBCfg.h"
#include "Dlog_Data.h"
#include "Dlog_SweGen.h"       /* defines Dlog_ProcessClassType        */
#include "Dlog_SweStatus.h"
#include <string.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_HweTable.c does not match the version of the module!"
#endif


/**
 * HWModel constants
 * \lhref FL931
*/
/**\{*/
#define DLOG_HWM_A_MUSTER 0x00u
#define DLOG_HWM_B_MUSTER 0x01u
#define DLOG_HWM_C_MUSTER 0x02u
#define DLOG_HWM_SERIAL   0x03u
/**\}*/

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
/*                      Hardware Description Data                             */
/* -------------------------------------------------------------------------- */


#define Dlog_START_SEC_CONST_BM_HW_DESCRIPTION_TABLE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
const Dlog_HwDescDataType Dlog_HwDescData = {
    /* HWE Sgbm Id = HardwareLogisticData                                      */
#if (DLOG_TOTALNUMBEROFHWESGBMIDS > 0u)
    {
        DLOG_HWE_TABLE
    },
    {DLOG_HWE_TABLE_INDICES},
#endif
    {
        /* ECUSerialNumber                                                         */
        {DLOG_ECUSERIALNUMBERDEFAULT},
        /* ECUManufacturingData                                                    */
        {DLOG_ECUMANUFACTURINGDATEDEFAULT},
        /* HW Modification Index                                                   */
        {0,
        (DLOG_HWM_A_MUSTER << 6) + 0},
        /* ECU UID */
        {DLOG_ECUUIDDEFAULT}
    }
};

#define Dlog_STOP_SEC_CONST_BM_HW_DESCRIPTION_TABLE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

Dlog_HweInfoType Dlog_HweInfos[DLOG_MAXNUMBEROFHWESGBMIDS];
uint8 Dlog_HweDevelopmentInfos[DLOG_MAXNUMBEROFHWESGBMIDS][DLOG_HWEDEVELOPMENTINFOLENGTH + 1]; /* ... plus one Byte length info */
Dlog_HWDataType Dlog_HWData;

#define Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

void Dlog_InitHweTable(void) {
#if (DLOG_TOTALNUMBEROFHWESGBMIDS > 0u)
  uint8 i;
#endif
  memcpy(&Dlog_HWData, &Dlog_HwDescData.hwData, sizeof(Dlog_HWData));
  Dlog_Data.hwData = &Dlog_HWData;
#if (DLOG_TOTALNUMBEROFHWESGBMIDS > 0u)
  Dlog_Data.numberOfHwe = Dlog_HwDescData.HweTableIndices[Dlog_PBConfigSetPtr->HweTable+1] -
                          Dlog_HwDescData.HweTableIndices[Dlog_PBConfigSetPtr->HweTable];

  for (i = 0; i < Dlog_Data.numberOfHwe; ++i) {
    (void)memcpy(
        Dlog_HweInfos[i].sgmbId,
        Dlog_HwDescData.HweTable[Dlog_HwDescData.HweTableIndices[Dlog_PBConfigSetPtr->HweTable] + i].sgbmId,
        sizeof(Dlog_HweInfos[i].sgmbId));
    (void)memcpy(
        Dlog_HweDevelopmentInfos[i],
        Dlog_HwDescData.HweTable[Dlog_HwDescData.HweTableIndices[Dlog_PBConfigSetPtr->HweTable] + i].developmentInfo,
        sizeof(Dlog_HweDevelopmentInfos[i]));
    Dlog_HweInfos[i].developmentInfo = Dlog_HweDevelopmentInfos[i];
  }
  Dlog_Data.hweInfo = &Dlog_HweInfos[0];
#endif
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


