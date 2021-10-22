
/**********************************************************************************************************************
* Copyright 2015, 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : DiagcMgr_Cfg.h
* Module Description: DiagcMgr
* Project           : CBD
* Author            : Spandana Balani
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:40
***********************************************************************************************************************
* Version Control:
* %version:          30 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                          SCR #
* -------   -------  --------  ---------------------------------------------------------------------------   ----------
* 03/11/16  1        SB         ES101A_DiagcMgr_Design version 2 implementation                              EA4#3421
* 04/19/16  2        SB         ES101A_DiagcMgr_Design version 3 implementation                              EA4#5110
* 05/23/16  3        SB         Updated to fix anomaly EA4#5865  NTC BF not setting                          EA4#5905
* 06/20/16  4        SB         ES101A_DiagcMgr_Design version 4 implementation                              EA4#6251
* 11/30/16  5        SB         Added DEMTOTNROFDTC_CNT_U08                                                  EA4#8662
* 12/06/16  6        SB         Removed Dem.h include                                                        EA4#8822
* 04/10/17  7        SR         Added CONST variable declarations for NtcPptyAry,
*                               DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM and DIAGCMGRNTCLTCHCNTRTHD_CNT_U08           EA4#10779
* 08/04/17  8        SR         The Ecuc file was updated with addiitonal DTCs so constant value changed     EA4#13175
* 09/12/17  9        SR         DIAGCMGRNTCMAP_CNT_REC and DIAGCMGRNTCPPTYARY_CNT_U08 array declarations
*                               and D_MAXNUMOFLTCHGNTCS_CNT_U16 constant declaration is moved to
*                               DiagcMgrStaticTypes.h since these aren't configurable                        EA4#14411
**********************************************************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
# ifndef DIAGMGR_CFG_H
#define DIAGMGR_CFG_H

#include "DiagcMgrStaticTypes.h"
#include "NxtrDet.h"

/*******************************************************************************
**                      Module Private Data                                   **
*******************************************************************************/

    /** Number of NTCs configured in an application, 
        typedef for variable size NTC Info Array PIMs, 
        Application NTC array, 
        Total number of Deounce type NTCs in an application, 
        typedef for variable size DebCntr Array PIMs    **/   
  
    /* Note: No NTCs Configured for SystemApplication */

    /* Note: No Debounce type NTCs Configured for SystemApplication */
    typedef sint16 Ary1D_s16_DiagcMgrProxyApplication[1U];
  
    /* Note: No NTCs Configured for Appl0 */

    /* Note: No Debounce type NTCs Configured for Appl0 */
    typedef sint16 Ary1D_s16_DiagcMgrProxyAppl0[1U];
  
    #define     NTCCNTAPPL10_CNT_U16                   184U
    typedef NtcInfoRec4 Ary1D_NtcInfoRec4_DiagcMgrProxyAppl10[NTCCNTAPPL10_CNT_U16];
    extern CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL10_CNT_U16[NTCCNTAPPL10_CNT_U16];

    #define     TOTDEBNTCINAPPLX10_CNT_U08               32U
    typedef sint16 Ary1D_s16_DiagcMgrProxyAppl10[TOTDEBNTCINAPPLX10_CNT_U08 + 1U];
  
    #define     NTCCNTAPPL7_CNT_U16                   3U
    typedef NtcInfoRec4 Ary1D_NtcInfoRec4_DiagcMgrProxyAppl7[NTCCNTAPPL7_CNT_U16];
    extern CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL7_CNT_U16[NTCCNTAPPL7_CNT_U16];

    #define     TOTDEBNTCINAPPLX7_CNT_U08               1U
    typedef sint16 Ary1D_s16_DiagcMgrProxyAppl7[TOTDEBNTCINAPPLX7_CNT_U08 + 1U];
  
    #define     NTCCNTAPPL8_CNT_U16                   2U
    typedef NtcInfoRec4 Ary1D_NtcInfoRec4_DiagcMgrProxyAppl8[NTCCNTAPPL8_CNT_U16];
    extern CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL8_CNT_U16[NTCCNTAPPL8_CNT_U16];

    #define     TOTDEBNTCINAPPLX8_CNT_U08               2U
    typedef sint16 Ary1D_s16_DiagcMgrProxyAppl8[TOTDEBNTCINAPPLX8_CNT_U08 + 1U];
  
    #define     NTCCNTAPPL9_CNT_U16                   2U
    typedef NtcInfoRec4 Ary1D_NtcInfoRec4_DiagcMgrProxyAppl9[NTCCNTAPPL9_CNT_U16];
    extern CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL9_CNT_U16[NTCCNTAPPL9_CNT_U16];

    #define     TOTDEBNTCINAPPLX9_CNT_U08               1U
    typedef sint16 Ary1D_s16_DiagcMgrProxyAppl9[TOTDEBNTCINAPPLX9_CNT_U08 + 1U];

    /* Number of DTCs configured */
    #define TOTNROFDTC_CNT_U08                          22U 
    typedef uint8 Ary1D_u08_DiagcMgr1[TOTNROFDTC_CNT_U08 + 1U]; 
    extern CONST(uint16, DiagcMgr_CODE) DTCENAMASK[TOTNROFDTC_CNT_U08 + 1U];
    extern CONST(uint16, DiagcMgr_CODE) DEMDTCEVEIDMAP[TOTNROFDTC_CNT_U08 + 1U];

    #define DIAGCMGR_DEMCHK                             STD_ON
#if ((STD_ON == NXTRDET_DIAGCMGR) && (STD_ON == DIAGCMGR_DEMCHK))
    
    #define DEMTOTNROFDTC_CNT_U08                       ((uint8)(DEM_CFG_GLOBAL_DTC_COUNT))
    
#endif

# endif
