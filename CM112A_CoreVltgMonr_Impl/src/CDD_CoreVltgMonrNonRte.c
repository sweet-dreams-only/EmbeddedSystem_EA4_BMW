/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_CoreVltgMonrNonRte.c
* Module Description: CoreVltgMonr component function for startup test for CVM
* Project           : CBD
* Author            : Avinash James
**********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
*   Date      Rev      Author       Change Description                                                       SCR #
* --------  -------  ----------  ---------------------------------------------------------------         -------------
* 07/28/17    1      AJM         Start up test for Core voltage monitor                                  EA4#13771
* 08/09/17    2      AJM         Added check for power on reset to execute start up test and 
                                 corrected the status mask value                                         EA4#14415
*********************************************************************************************************************/
#include "Rte_CDD_CoreVltgMonr.h"
#include "CDD_CoreVltgMonr.h"
#include "NxtrMcuSuprtLib.h"
#include "sys_regs.h"
#include "CDD_ExcpnHndlg.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* MISRA-C:2004 Rule 19.1 : [NXTRDEV 19.1.1]  : AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 2.1  : [NXTRDEV 2.1.2]   : Deviation allowed for "nop" instructions in delay loop in CVM startup test because the code
                                                runs before MCAL initialization and so no timers are available */ 

#define COREVLTGMONRFACMASK_CNT_U08             (131U)
#define COREVLTGMONRDIAGCCTRLMASK_CNT_U08       (12U)
#define COREVLTGMONROUTCTRLMASK_CNT_U08         (8U)
#define COREVLTGMONRRSTENAMASK_CNT_U32          (3U)
#define LOOPCNTRTHD_CNT_U08                     (5U)
#define COREVLTGMONRCLRFLTPRMBYTE_CNT_U08       (4U)
#define ERRINDCNFLTPRMBYTE_CNT_U08              (2U)
#define DLYTMRCNT_CNT_U16                       (1920U)
#define COREVLTGMONRFLTDETNMASK_CNT_U08         (3U)
#define COREVLTGMONROUTSTSMASK_CNT_U08          (4U)

static FUNC(void, CDD_CoreVltgMonr_CODE) Dly12MicroSec(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define CoreVltgMonr_START_SEC_CODE
#include "CDD_CoreVltgMonr_MemMap.h" 

/**********************************************************************************************************************
  * Name:        CoreVltgMonrInit1
  * Description: Non-Rte Init function to execute CVM start up test
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called during initialization sequence before  
  ********************************************************************************************************************/
FUNC(void, CDD_CoreVltgMonr_CODE) CoreVltgMonrInit1(void) 
{
    VAR(uint8, AUTOMATIC) LoopCntr_Cnt_T_u08;
    VAR(McuDiagc1, AUTOMATIC) McuDiagcData0_Cnt_T_enum;
    
    GetMcuDiagcIdnData(&McuDiagcData0_Cnt_T_enum);
    
    if(McuDiagcData0_Cnt_T_enum == MCUDIAGC_PWRONRST)
    {
        /* Mask CVM Out */
        WrProtdRegSys_u08(1U,&SYSCVMDMASK);
        
        LoopCntr_Cnt_T_u08 = LOOPCNTRTHD_CNT_U08;
        /* Verify CVMF */
        while((LoopCntr_Cnt_T_u08 > 0U) && ((SYSCVMF & COREVLTGMONRFACMASK_CNT_U08) != 0U))
        {
            WrProtdRegSys_u08(COREVLTGMONRFACMASK_CNT_U08,&SYSCVMFC);
            LoopCntr_Cnt_T_u08--;
        }
        
        if((SYSCVMF & COREVLTGMONRFACMASK_CNT_U08) != 0U)
        {
            *Rte_Pim_CoreVltgMonrStrtUpFltPrmByte() = 1U;
        }
        else
        {
            /* Do Nothing */
        }
        /* End Verify CVMF */
        
        /* Enable Diag mode to forcibly generate high and low voltage condition */
        WrProtdRegSys_u08(COREVLTGMONRDIAGCCTRLMASK_CNT_U08,&SYSCVMDIAG);
        Dly12MicroSec();
      
        if((SYSCVMF & COREVLTGMONRFACMASK_CNT_U08) == COREVLTGMONRFLTDETNMASK_CNT_U08)
        {
            WrProtdRegSys_u08(0U,&SYSCVMDIAG);
            Dly12MicroSec();
            
            WrProtdRegSys_u08(COREVLTGMONRFACMASK_CNT_U08,&SYSCVMFC);
            
            LoopCntr_Cnt_T_u08 = LOOPCNTRTHD_CNT_U08;
            
            while((LoopCntr_Cnt_T_u08 > 0U) && ((SYSCVMF & COREVLTGMONRFACMASK_CNT_U08) != 0U))
            {
                WrProtdRegSys_u08(COREVLTGMONRFACMASK_CNT_U08,&SYSCVMFC);
                LoopCntr_Cnt_T_u08--;
            }

            if((SYSCVMF & COREVLTGMONRFACMASK_CNT_U08) != 0U)
            {
                *Rte_Pim_CoreVltgMonrStrtUpFltPrmByte() |= COREVLTGMONRCLRFLTPRMBYTE_CNT_U08;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            *Rte_Pim_CoreVltgMonrStrtUpFltPrmByte() |= ERRINDCNFLTPRMBYTE_CNT_U08;
        }
        WrProtdRegSys_u08(0U,&SYSCVMDMASK); 
        
        WrProtdRegSys_u08(COREVLTGMONROUTCTRLMASK_CNT_U08,&SYSCVMDEW);

        LoopCntr_Cnt_T_u08 = LOOPCNTRTHD_CNT_U08;
        
        while((LoopCntr_Cnt_T_u08 > 0U) && ((SYSCVMDE & COREVLTGMONROUTSTSMASK_CNT_U08)  != COREVLTGMONROUTSTSMASK_CNT_U08))
        {
            WrProtdRegSys_u08(COREVLTGMONROUTCTRLMASK_CNT_U08,&SYSCVMDEW);
            LoopCntr_Cnt_T_u08--;
        }
        
        if((SYSCVMDE & COREVLTGMONROUTSTSMASK_CNT_U08)  != COREVLTGMONROUTSTSMASK_CNT_U08)
        {
            *Rte_Pim_CoreVltgMonrStrtUpFltPrmByte() |= COREVLTGMONROUTCTRLMASK_CNT_U08;
        }
        else
        {
            /* Do Nothing */
        }

        WrProtdRegSys_u32(COREVLTGMONRRSTENAMASK_CNT_U32,&SYSCVMREN);
    }
    else
    {
        /* Do nothing */
    }

}


/**********************************************************************************************************************
  * Name:        Dly12MicroSec
  * Description: Delay function for a minimum of 12uSec
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during start up test.The rationale being Nop() instruction takes
                 1 instruction cycle 
  ********************************************************************************************************************/
static FUNC(void, CDD_CoreVltgMonr_CODE) Dly12MicroSec(void)
{
    VAR(uint16, AUTOMATIC) LoopCntr_Cnt_T_u16 = DLYTMRCNT_CNT_U16;
    while(LoopCntr_Cnt_T_u16 > 0U)
    {
        LoopCntr_Cnt_T_u16--;
        __asm("nop");
    }
}

#define CoreVltgMonr_STOP_SEC_CODE
#include "CDD_CoreVltgMonr_MemMap.h" 





