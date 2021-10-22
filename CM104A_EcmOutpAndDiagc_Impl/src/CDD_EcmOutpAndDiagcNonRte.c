/**********************************************************************************************************************
* Copyright 2015,2016,2017 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_EcmOutpAndDiagcNonRte.c
* Module Description: Error Control Module Output and Diagnostics Complex Driver NonRte Functionality
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          9 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/06/15  1        LWW       Initial Version                                                                 EA4#1847
* 02/05/16  2        AJM       Updates for the EI and Pseudo Error Injection start up tests					   EA4#3683
* 04/04/16  3        Selva     Implemented to v03.01.00 of the FDD                                             EA4#5098
* 06/24/16  4        Selva     Implemented to v03.03.00 of the FDD                                             EA4#6265
* 08/03/16  5        AJM       Corrected the conditions in Init3, added logic for MCUDIAGC_ECMSTSSTRTUPFLT	   EA4#6661
                               in Init4
* 11/15/16  6        AJM       Fault injection through conditional compilation                                 EA4#6941
* 03/20/17  7        AJM       Corrected the fault injetion sequence and the fault Id's                        EA4#10597
* 06/05/17  8        AJM       Removed dependency on OS APIs                                                   EA4#11811
* 07/14/17  9        AJM       Removed uDiag error case 0x00260102                                             EA4#13346
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include <v800_ghs.h> /* for SYNCM intrinsic */  
#include "Os.h"
#include "CDD_EcmOutpAndDiagc.h"
#include "NxtrMcuSuprtLib.h"
#include "CDD_ExcpnHndlg.h"
#include "ecm_regs.h"
#include "intc_regs.h"
#include "Std_Types.h"
#include "McuErrInj.h"

/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/
#define CDD_EcmOutpAndDiagc_START_SEC_CODE
#include "CDD_EcmOutpAndDiagc_MemMap.h"

/**********************************************************************************************************************
  * Name:        EcmOutpAndDiagcInit1
  * Description: Non-RTE initialization function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during initialization prior to the O/S starting
  ********************************************************************************************************************/
FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit1(void)
{
    VAR(uint32, AUTOMATIC) ECMMSSE131_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMCSSE131_Cnt_T_u32;
    VAR(boolean, AUTOMATIC) ExecStrtUpTest_Cnt_T_logl;
    #if(MCUDIAGCERRINJ == STD_ON)
    VAR(uint32, AUTOMATIC) McuDiagcData0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
    #endif
    ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl);

    #if(MCUDIAGCERRINJ == STD_ON)
    GetMcuDiagcIdnData(&McuDiagcData0_Cnt_T_u32);
    ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
    if ((ECMMSSE131 == 1U) &&(ECMCSSE131 == 1U)&& ((ExecStrtUpTest_Cnt_T_logl== TRUE) || 
       (McuDiagcData0_Cnt_T_u32 == MCUDIAGC_MCUDIAGCTEST)))
    #else
    /* Check if If ERROROUT output is normal output AND
    ECMmESSTR1 Bit 31 is the loopback bit which is expected to be HIGH after Mcu_Init */
    if ((ECMMSSE131 == 1U) &&(ECMCSSE131 == 1U)&& (ExecStrtUpTest_Cnt_T_logl== TRUE))
    #endif
    {
        /* Set ERROROUT output Low by only changing the value in ECMMESET Master Register */
        CtrlErrOut_Oper(STD_LOW, TRIGREG_MST);
        /* Fault Injection Point 1 */
        #if(MCUDIAGCERRINJ == STD_ON)
        if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT02CASE01_CNT_U32)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();
            CtrlErrOut_Oper (STD_HIGH, TRIGREG_MST);
        }
        #endif

        ECMMSSE131_Cnt_T_u32 = ECMMSSE131;
        ECMCSSE131_Cnt_T_u32 = ECMCSSE131;
        
        if ((ECMMSSE131_Cnt_T_u32 == 1U) || (ECMCSSE131_Cnt_T_u32 == 1U))
        {
            SetMcuDiagcIdnData(MCUDIAGC_MSTERROUTPCTRLFLT, ECMMESSTR1);
        }
        else
        {
            /* Set ERROROUT output High by changing the value in ECMMESET (Master) Register */
            CtrlErrOut_Oper(STD_HIGH, TRIGREG_MST);

            ECMMSSE131_Cnt_T_u32 = ECMMSSE131;
            ECMCSSE131_Cnt_T_u32 = ECMCSSE131;
        
            if ((ECMMSSE131_Cnt_T_u32 == 1U) && (ECMCSSE131_Cnt_T_u32 == 1U))
            {
                /* Set ERROROUT output Low by only changing the value in ECMCESET Checker Register */
                CtrlErrOut_Oper(STD_LOW, TRIGREG_CHKR);
                
                /* Fault Injection Point 2 */
                #if (MCUDIAGCERRINJ == STD_ON)
                if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT03CASE01_CNT_U32)
                {
                    /*Clear BRAMDAT2 Register*/
                    ClrErrInjReg_Oper();
                    CtrlErrOut_Oper(STD_HIGH,TRIGREG_MST);
                }
                #endif
                
                ECMMSSE131_Cnt_T_u32 = ECMMSSE131;
                ECMCSSE131_Cnt_T_u32 = ECMCSSE131;
            
                if ((ECMMSSE131_Cnt_T_u32 == 1U) || (ECMCSSE131_Cnt_T_u32 == 1U))
                {
                    SetMcuDiagcIdnData(MCUDIAGC_CHKRERROUTPCTRLFLT, ECMMESSTR1);
                }
                else
                {
                    /* Set ERROROUT output High by changing the value in ECMCESET (Checker) Register */
                    CtrlErrOut_Oper(STD_HIGH, TRIGREG_CHKR);
                }
            }
        }
    }
    else
    {
        /* Do nothing because if there was a fault, it will be handled later in the application*/
    }
}

/**********************************************************************************************************************
  * Name:        EcmOutpAndDiagcInit3
  * Description: Non-RTE initialization function for EI Start Up Test
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during initialization prior to the O/S starting
  ********************************************************************************************************************/
FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit3(void)
{
    #ifndef OSKERNELVERSION7ORHIGHER
    VAR(uint8, AUTOMATIC) MaskState_Cnt_T_u08;
    VAR(uint16, AUTOMATIC) EIC8_Val_Cnt_T_u16;
    #else
    VAR(boolean, AUTOMATIC) IntrptEnad_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) IntrptPnd_Cnt_T_logl;
    #endif

    VAR(boolean, AUTOMATIC) ExecStrtUpTest_Cnt_T_logl;

    VAR(uint32, AUTOMATIC) ECMMICFG1_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMESSTC1_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMMICFG1Saved_Cnt_T_u32;
    VAR(McuDiagc1, AUTOMATIC) DiagcIdn_Cnt_T_enum;
    VAR(uint32, AUTOMATIC) ECMMESSTR0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMCESSTR0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMMESSTR1_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMCESSTR1_Cnt_T_u32;
    #if(MCUDIAGCERRINJ == STD_ON)
    VAR(uint32, AUTOMATIC) McuDiagcData0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMPE1Desired_Cnt_T_u32;

    GetMcuDiagcIdnData (&McuDiagcData0_Cnt_T_u32);
    ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

    /* Fault Injection Point 1 */
    if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0021BIT07CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        /* FACI Reset Error */
        ECMPE1Desired_Cnt_T_u32 = 0x00000400U;
        WrProtdRegEcm_u32 (ECMPE1Desired_Cnt_T_u32,&ECMPE1);
    }
    /* Fault Injection Point 3 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT00CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper ();
        /* ECM Start Up Error */
        ECMPE1Desired_Cnt_T_u32 = 0x00000040U;
        WrProtdRegEcm_u32 (ECMPE1Desired_Cnt_T_u32, &ECMPE1);
    }
    else
    {
        /* Do nothing */
    }
    #endif

    ECMMESSTR0_Cnt_T_u32 = ECMMESSTR0;
    ECMCESSTR0_Cnt_T_u32 = ECMCESSTR0;
    ECMMESSTR1_Cnt_T_u32 = ECMMESSTR1;
    ECMCESSTR1_Cnt_T_u32 = ECMCESSTR1;

    ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl);


    #if (MCUDIAGCERRINJ == STD_ON)
    if(((ExecStrtUpTest_Cnt_T_logl == TRUE) || (McuDiagcData0_Cnt_T_u32 == MCUDIAGC_MCUDIAGCTEST)) && (ECMMESSTR0_Cnt_T_u32 == 0x0U) && (ECMCESSTR0_Cnt_T_u32 == 0x0U) && (ECMMESSTR1_Cnt_T_u32 == 0x0U) && (ECMCESSTR1_Cnt_T_u32 == 0x0U))
    #else
    if((ExecStrtUpTest_Cnt_T_logl == TRUE) && (ECMMESSTR0_Cnt_T_u32 == 0x0U) && (ECMCESSTR0_Cnt_T_u32 == 0x0U) && (ECMMESSTR1_Cnt_T_u32 == 0x0U) && (ECMCESSTR1_Cnt_T_u32 == 0x0U))
    #endif
    {
        /* Global disable all EINT interrupts */
        SuspendAllInterrupts();
        
        ECMMICFG1Saved_Cnt_T_u32 =  ECMMICFG1;
        /* Set the bit ECMMIE110 of the ECMMICFG1 register to enable it as an EI Interrupt */
        ECMMICFG1_Desired_Cnt_T_u32 = ECMMICFG1Saved_Cnt_T_u32 | (0x00000400U);
        /* Fault Injection Point 2 */
        #if (MCUDIAGCERRINJ == STD_ON)
        if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT01CASE01_CNT_U32)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper ();
            /* Disable generation of EI Interrupt */
            ECMMICFG1_Desired_Cnt_T_u32 = 0x00000000U;
        }
        #endif

        /* Get the Interrupt Mask Status */
        MaskState_Cnt_T_u08 = (uint8)(INTC1EIC8 & 0x0080U);
        /* Enable Interrupt Processing */
        INTC1EIC8 &= (uint16)0xFF7FU;
        
        WrProtdRegEcm_u32(ECMMICFG1_Desired_Cnt_T_u32,&ECMMICFG1);
        
        /* Generate ECM error using pseudo trigger register for the error source configured for EI interrupt.
        For the purpose of this test, ECMmSSE110 is chosen to invoke an EI Interrupt*/
        WrProtdRegEcm_u32 ((0x00000400U), &ECMPE1);
        
        /* Ensure the Error is injected before we check for the interrupt flag */
        __SYNCM();

        /* Read the EIC8 Register */
        EIC8_Val_Cnt_T_u16 = INTC1EIC8;
        /* At this point ECM EI level ISR will NOT be executed but the EIC8.EIRFn will be set to 1 */
        if ((EIC8_Val_Cnt_T_u16 & 0x1000U) == 0U) 
        {
            
            SetMcuDiagcIdnData(MCUDIAGC_EIINTRPTSTRTUPFLT, (uint32)EIC8_Val_Cnt_T_u16);
        }
        /* Clear the interrupt request flag */
        INTC1EIC8 &= 0xEFFFU;
        if (MaskState_Cnt_T_u08 != 0U)
        {
            /* Disable interrupt processing for ECM EI interrupt;  */
            INTC1EIC8 |= 0x0080U;
        }
        
        /* Clear the bit ECMMIE110 of the ECMMICFG1 register to disable it as an EI Interrupt */
        ECMMICFG1_Desired_Cnt_T_u32 =  ECMMICFG1Saved_Cnt_T_u32;
        WrProtdRegEcm_u32 (ECMMICFG1_Desired_Cnt_T_u32, &ECMMICFG1);

        /* Clear the bit ECMmSSE110 bit of the ECMmESSTR1 register */
        ECMESSTC1_Desired_Cnt_T_u32 = ECMESSTC1 | (0x00000400U);
        WrProtdRegEcm_u32 (ECMESSTC1_Desired_Cnt_T_u32,&ECMESSTC1);

        ResumeAllInterrupts();
    }
    else if((ECMMSSE110 == 1U) || (ECMCSSE110 == 1U))
    {
        SetMcuDiagcIdnData(MCUDIAGC_FACIRSTTRFERR, 0U);
    }
    else if(((ECMMESSTR0_Cnt_T_u32 != 0x0U) ||
        (ECMCESSTR0_Cnt_T_u32 != 0x0U) ||
        (ECMMESSTR1_Cnt_T_u32 != 0x0U) ||
        (ECMCESSTR1_Cnt_T_u32 != 0x0U)))
    {
        /*	 The ECM Status Bits get cleared in the MCU Init following this Function*/
        GetMcuDiagcIdnData(&DiagcIdn_Cnt_T_enum);
        if(DiagcIdn_Cnt_T_enum != MCUDIAGC_ECMRST)
        {
            SetMcuDiagcIdnData(MCUDIAGC_ECMSTSSTRTUPFLT, 0U);
        }
    }
    else
    {
        /************* Do nothing****************/
    }
}

/**********************************************************************************************************************
  * Name:        EcmOutpAndDiagcInit4
  * Description: Non-RTE initialization function for Pseudo Error Injection Start Up Test
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during initialization prior to the O/S starting
  ********************************************************************************************************************/
FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit4(void)
{

    VAR(boolean, AUTOMATIC) ExecStrtUpTest_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) ECMMICFG0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMNMICFG0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMIRCFG0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMMICFG1_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMNMICFG1_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMIRCFG1_Cnt_T_u32;

    VAR(uint32, AUTOMATIC) ECMMESSTR0_Cnt_T_u32 = ECMMESSTR0;
    VAR(uint32, AUTOMATIC) ECMCESSTR0_Cnt_T_u32 = ECMCESSTR0;
    VAR(uint32, AUTOMATIC) ECMMESSTR1_Cnt_T_u32 = ECMMESSTR1;
    VAR(uint32, AUTOMATIC) ECMCESSTR1_Cnt_T_u32 = ECMCESSTR1;

    VAR(uint32, AUTOMATIC) ECMMICFG0_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMNMICFG0_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMIRCFG0_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMMICFG1_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMNMICFG1_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMIRCFG1_Desired_Cnt_T_u32;

    VAR(uint32, AUTOMATIC) ECMPE0_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMPE1_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMESSTC0_Desired_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ECMESSTC1_Desired_Cnt_T_u32;

    VAR(boolean, AUTOMATIC) ECMMESSTR0_Desired_Cnt_T_lgc = FALSE;
    VAR(boolean, AUTOMATIC) ECMMESSTR1_Desired_Cnt_T_lgc = FALSE;
    #if(MCUDIAGCERRINJ == STD_ON)
    VAR(uint32, AUTOMATIC) McuDiagcData0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
    #endif

    ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl);

    #if (MCUDIAGCERRINJ == STD_ON)
    GetMcuDiagcIdnData(&McuDiagcData0_Cnt_T_u32);
    ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
    #endif

    if((ExecStrtUpTest_Cnt_T_logl == TRUE)
    #if (MCUDIAGCERRINJ == STD_ON)
    || (McuDiagcData0_Cnt_T_u32 == MCUDIAGC_MCUDIAGCTEST)
    #endif
    )
    {
        if ((ECMMESSTR0_Cnt_T_u32 == 0U) && (ECMCESSTR0_Cnt_T_u32 == 0U) && (ECMMESSTR1_Cnt_T_u32 == 0x80000000U) && 
        (ECMCESSTR1_Cnt_T_u32 == 0x80000000U))
        {
            ECMMICFG0_Cnt_T_u32 = ECMMICFG0;
            ECMNMICFG0_Cnt_T_u32 = ECMNMICFG0;
            ECMIRCFG0_Cnt_T_u32 = ECMIRCFG0;

            ECMMICFG1_Cnt_T_u32 = ECMMICFG1;
            ECMNMICFG1_Cnt_T_u32 = ECMNMICFG1;
            ECMIRCFG1_Cnt_T_u32 = ECMIRCFG1;


            /* Set the ALL bits of the ECMMICFG0 register to prohibited */
            ECMMICFG0_Desired_Cnt_T_u32 = ECMMICFG0 & (~((uint32)0xFDFFDFF3U));
            WrProtdRegEcm_u32 (ECMMICFG0_Desired_Cnt_T_u32, &ECMMICFG0);

            /* Set the ALL bits of the ECMNMICFG0 register to prohibited */
            ECMNMICFG0_Desired_Cnt_T_u32 = ECMNMICFG0 & (~((uint32)0xFDFFDFF3U));
            WrProtdRegEcm_u32 (ECMNMICFG0_Desired_Cnt_T_u32, &ECMNMICFG0);

            /* Set the ALL bits of the ECMIRCFG0register to prohibited */
            ECMIRCFG0_Desired_Cnt_T_u32 = ECMIRCFG0 & (~((uint32)0xFDFFDFF3U));
            WrProtdRegEcm_u32 (ECMIRCFG0_Desired_Cnt_T_u32, &ECMIRCFG0);

            /* Set the ALL bits of the ECMMICFG1 register to prohibited */
            ECMMICFG1_Desired_Cnt_T_u32 = ECMMICFG1 & (~((uint32)0x000007F7U));
            WrProtdRegEcm_u32 (ECMMICFG1_Desired_Cnt_T_u32, &ECMMICFG1);

            /* Set the ALL bits of the ECMNMICFG1 register to prohibited */
            ECMNMICFG1_Desired_Cnt_T_u32 = ECMNMICFG1 & (~((uint32)0x000007F7U));
            WrProtdRegEcm_u32 (ECMNMICFG1_Desired_Cnt_T_u32, &ECMNMICFG1);

            /* Set the ALL bits of the ECMIRCFG1 register to prohibited */
            ECMIRCFG1_Desired_Cnt_T_u32 = ECMIRCFG1 & (~((uint32)0x200007F7U));
            WrProtdRegEcm_u32 (ECMIRCFG1_Desired_Cnt_T_u32, &ECMIRCFG1);

            ECMPE0_Desired_Cnt_T_u32 = 0xFDFFDFF3U;
            ECMPE1_Desired_Cnt_T_u32 = 0x200007F7U;
            
            #if (MCUDIAGCERRINJ == STD_ON)
            /* Fault Injection Point 1 */
            if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT04CASE01_CNT_U32)
            {
                /*Clear BRAMDAT2 Register*/
                ClrErrInjReg_Oper();
                ECMPE0_Desired_Cnt_T_u32 = 0x00000000U;
                ECMPE1_Desired_Cnt_T_u32 = 0x00000000U;
            }
            #endif
            /* Inject all errors by setting the corresponding bit in ECMPEn	*/
            WrProtdRegEcm_u32 (ECMPE0_Desired_Cnt_T_u32, &ECMPE0);
            WrProtdRegEcm_u32 (ECMPE1_Desired_Cnt_T_u32, &ECMPE1);

            /* Check ERROROUT output state */
            if (ECMMSSE131 == 0U)
            {
                /* Set the ERROROUT pin to inactive state, HIGH */
                CtrlErrOut_Oper(STD_HIGH,TRIGREG_MSTANDCHKR);
                
                ECMESSTC0_Desired_Cnt_T_u32 = 0xFDFFDFF3U;
                ECMESSTC1_Desired_Cnt_T_u32 = 0x600007F7U;

                #if (MCUDIAGCERRINJ == STD_ON)
                if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT04CASE02_CNT_U32)
                {
                    /* Clear BRAMDAT2 Register */
                    ClrErrInjReg_Oper();
                    /* Fault Injection Point 2 */
                    ECMESSTC0_Desired_Cnt_T_u32 = 0x00000000U;
                    ECMESSTC1_Desired_Cnt_T_u32 = 0x00000000U;
                }
                #endif
                
                /* Clear all errors by setting the corresponding bit in ECMESSTCn */
                WrProtdRegEcm_u32 (ECMESSTC0_Desired_Cnt_T_u32, &ECMESSTC0);

                WrProtdRegEcm_u32 (ECMESSTC1_Desired_Cnt_T_u32, &ECMESSTC1);

                if(ECMMESSTR0 != 0x0U)
                {
                    ECMMESSTR0_Desired_Cnt_T_lgc = TRUE;
                }
                if(ECMMESSTR1 != 0x80000000U)
                {
                    ECMMESSTR1_Desired_Cnt_T_lgc = TRUE;
                }
                
                if ( (ECMMESSTR0_Desired_Cnt_T_lgc == TRUE) && (ECMMESSTR1_Desired_Cnt_T_lgc == TRUE))
                {
                    SetMcuDiagcIdnData (MCUDIAGC_ECMPSDOERRINJFLT, 1U);
                }
            }
            else
            {
                SetMcuDiagcIdnData (MCUDIAGC_ECMPSDOERRINJFLT, 2U);
            }

            /* Write back the initial values of ECMMICFG0, ECMNMICFG0 and ECMIRCFG0 */
            WrProtdRegEcm_u32 (ECMMICFG0_Cnt_T_u32, &ECMMICFG0);
            WrProtdRegEcm_u32 (ECMNMICFG0_Cnt_T_u32, &ECMNMICFG0);
            WrProtdRegEcm_u32 (ECMIRCFG0_Cnt_T_u32, &ECMIRCFG0);

            /* Write back the initial values of  ECMMICFG1, ECMNMICFG1 and ECMIRCFG1 */	
            WrProtdRegEcm_u32 (ECMMICFG1_Cnt_T_u32, &ECMMICFG1);
            WrProtdRegEcm_u32 (ECMNMICFG1_Cnt_T_u32, &ECMNMICFG1);
            WrProtdRegEcm_u32 (ECMIRCFG1_Cnt_T_u32, &ECMIRCFG1);
        }
        else
        {
            /* Bit was set during the window where the EcmOutpAndDiagcInit3 ends and the MCU_Init() configuration is complete */
            SetMcuDiagcIdnData(MCUDIAGC_ECMSTSSTRTUPFLT, 0U);
        }
    }

}

#if (MCUDIAGCERRINJ == STD_ON)
/**********************************************************************************************************************
  * Name:        InjEcmMstChkrRtErr
  * Description: Non-RTE function for injecting master checker run time error
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called on event from DF003
  ********************************************************************************************************************/
FUNC(void, CDD_EcmOutpAndDiagc_CODE) InjEcmMstChkrRtErr(void)
{
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;

    ReadErrInjReg_Oper (&ErrId_Cnt_T_u32);
    if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT07CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper ();
        /* Force ErrorOut pin to change state on the Master Register only, without disabling the ECM Compare Fault Interrupt */
        WrProtdRegEcmm_u08(0x01U, &ECMMESET);
    }
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0026BIT07CASE02_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper ();
        /* Force ErrorOut pin to change state on the Checker Register only, without disabling the ECM Compare Fault Interrupt */
        WrProtdRegEcmc_u08(0x01U, &ECMCESET);
    }
    else
    {
        /* Do nothing */
    }

}

/**********************************************************************************************************************
  * Name:        InjUkwnStrtUpDetdErr
  * Description: Non-RTE function for unknown startup detected error
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called on event from DF003
  ********************************************************************************************************************/
FUNC(void, CDD_EcmOutpAndDiagc_CODE) InjUkwnStrtUpDetdErr(void)
{
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) Ecmircfg1_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) Ecmpe1_Cnt_T_u32;

    ReadErrInjReg_Oper (&ErrId_Cnt_T_u32);
    if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0029BIT01CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper ();
        /* Configure for reset on error source 38, then set error source 38 pseudo error bit */
        Ecmircfg1_Cnt_T_u32 = (ECMIRCFG1 | 0x00000040U);
        Ecmpe1_Cnt_T_u32 = (ECMPE1 | 0x00000040U);
        WrProtdRegEcm_u32(Ecmircfg1_Cnt_T_u32 , &ECMIRCFG1);
        WrProtdRegEcm_u32(Ecmpe1_Cnt_T_u32 , &ECMPE1);
    }
}
#endif

#define CDD_EcmOutpAndDiagc_STOP_SEC_CODE
#include "CDD_EcmOutpAndDiagc_MemMap.h"
