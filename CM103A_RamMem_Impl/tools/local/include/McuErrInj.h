/**********************************************************************************************************************
* Copyright 2017, 2018 Nxtr
* Nxtr Confidential
*
* Module File Name  : McuErrInj.h
* Module Description: Micro Diag Error Injection stub header file
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       nz3893 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* -------   -------  --------  ---------------------------------------------------------------------------    ---------
* 07/27/17  1        AJM       Initial version                                                                EA4#13350
* 09/22/17  2        AJM       CM103A updates based on Renesas Feedback                                       EA4#15081
* 07/11/18  3        BLS       Updated to match latest header in DF003A_McuErrInj_Impl                        EA4#25009
**********************************************************************************************************************/
#ifndef MCUERRINJ_H
#define MCUERRINJ_H

#include "lockstep_regs.h"
#include "csih_regs.h"
#include "rscan_regs.h"
#include "dma_regs.h"
#include "flxa_regs.h"
#include "ecc_regs.h"
#include "NxtrMcuSuprtLib.h"
#include <v800_ghs.h> /* For SYNCM Intrinsic */
#include <string.h>

extern void ClrErrInjReg_Oper(void);
extern void ReadErrInjReg_Oper(uint32* ErrId);

#define MCUDIAGCERRINJ  STD_OFF


#if (MCUDIAGCERRINJ == STD_ON)
    #define MCUERRINJ_CPU1PEID_CNT_U32              ((uint32)0x01U)
    #define MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32     ((uint32)0x03U)  /* Peripheral to Local RAM SPID = 3U - Not used */
    #define MCUERRINJ_LCLRAMTOPRPHLSPID_CNT_U32     ((uint32)0x02U)  /* Local RAM to Peripheral SPID = 2U - Not used */
    #define MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32    ((uint32)0x00U)  /* Local RAM to Local RAM SPID = 0U */
    #define MCUERRINJ_USRMODENA_CNT_U32             ((uint32)0x1U)   /* User Mode Bit : 1: User Mode Access Allowed - Not used */
    #define MCUERRINJ_USRMODDI_CNT_U32              ((uint32)0x0U)   /* User Mode Bit : 0: Supervisor Mode access only */

    #define MCUERRINJ_SNGBITECCERRADR1_CNT_U32      ((uint32)0x0100A000U)
    #define MCUERRINJ_SNGBITECCERRADR2_CNT_U32      ((uint32)0x0100A010U)
    #define MCUERRINJ_DBLBITECCERRADR_CNT_U32       ((uint32)0x0100A8B0U)

    extern volatile uint32 McuDiagcTestVar1_G;
    extern volatile uint32 McuDiagcTestVar2_G;
    extern volatile uint32 McuDiagcTestAry_G[8U];
    extern volatile VAR(uint32, AUTOMATIC) DmaWrDataVar_G[4U];
    extern FUNC(void, CDD_RamMem_CODE) InjRamErr(void);

    /* CM103A - RamMem */
    #define MCUERRINJ_NTC0012BIT06CASE01_CNT_U32      0x00124001U
    #define MCUERRINJ_NTC0012BIT06CASE02_CNT_U32      0x00124002U
    #define MCUERRINJ_NTC0012BIT06CASE03_CNT_U32      0x00124003U
    #define MCUERRINJ_NTC0012BIT06CASE04_CNT_U32      0x00124004U
    #define MCUERRINJ_NTC0017BIT01CASE01_CNT_U32      0x00170201U
    #define MCUERRINJ_NTC0018BIT01CASE01_CNT_U32      0x00180201U
    #define MCUERRINJ_NTC0019BIT01CASE01_CNT_U32      0x00190201U
    #define MCUERRINJ_NTC001ABIT01CASE01_CNT_U32      0x001A0201U
    #define MCUERRINJ_NTC0012BIT04CASE01_CNT_U32      0x00121001U
    #define MCUERRINJ_NTC001BBIT01CASE01_CNT_U32      0x001B0201U
    #define MCUERRINJ_NTC0012BIT05CASE01_CNT_U32      0x00122001U
    #define MCUERRINJ_NTC001DBIT01CASE01_CNT_U32      0x001D0201U
    #define MCUERRINJ_NTC0016BIT01CASE01_CNT_U32      0x00160201U
    #define MCUERRINJ_NTC0012BIT03CASE01_CNT_U32      0x00120801U
    #define MCUERRINJ_NTC0012BIT00CASE01_CNT_U32      0x00120101U
    #define MCUERRINJ_NTC0012BIT00CASE02_CNT_U32      0x00120102U
    #define MCUERRINJ_NTC0012BIT00CASE03_CNT_U32      0x00120103U
    #define MCUERRINJ_NTC0012BIT00CASE04_CNT_U32      0x00120104U
    #define MCUERRINJ_NTC0012BIT00CASE05_CNT_U32      0x00120105U
    #define MCUERRINJ_NTC0012BIT00CASE06_CNT_U32      0x00120106U
    #define MCUERRINJ_NTC0012BIT00CASE07_CNT_U32      0x00120107U
    #define MCUERRINJ_NTC0012BIT00CASE08_CNT_U32      0x00120108U
    #define MCUERRINJ_NTC0012BIT00CASE09_CNT_U32      0x00120109U
    #define MCUERRINJ_NTC0012BIT00CASE0A_CNT_U32      0x0012010AU
    #define MCUERRINJ_NTC0013BIT01CASE01_CNT_U32      0x00130201U
    #define MCUERRINJ_NTC0013BIT01CASE02_CNT_U32      0x00130202U
    #define MCUERRINJ_NTC0013BIT00CASE01_CNT_U32      0x00130101U
    #define MCUERRINJ_NTC0013BIT00CASE02_CNT_U32      0x00130102U
    #define MCUERRINJ_NTC0013BIT02CASE01_CNT_U32      0x00130401U
    #define MCUERRINJ_NTC0012BIT02CASE01_CNT_U32      0x00120401U
#endif

#endif /* MCUERRINJ_H */
