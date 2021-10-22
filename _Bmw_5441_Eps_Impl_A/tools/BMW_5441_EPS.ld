/*===========================================================================*/
/* Module       = BMW_5441_EPS.ld                                            */
/* Version      = E1.00f                                                     */
/*                extracted from device file dr7f701311.dvf                  */
/*                by DeFiXRH850 0.7.5.2                                      */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2014 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose:     Template of linker directive file                            */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* Environment:                                                              */
/*              Device:         R7F701311                                    */
/*              IDE:            GHS Multi for V800  V6.xx or later           */
/*===========================================================================*/

/**********************************************************************************************************************
* Module File Name  : BMW_5441_EPS.ld
* Module Description: BMW Linker Directive File
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          12 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 08/30/17  1        KJS       Initial Creation of this file
* 11/23/17  2        AR        Updates for checksum symbols                                                   EA4#17066
* 01/03/18  3        AR        Updates to initialize newly added applications                                 EA4#XXXXX
* 04/10/18  4-8      AR        Multiple updates - Bootloader support, Calibration support are added           EA4#22226
* 07/20/18  12       AR        Updated for 2MB flash support                                                  EA4#26182
**********************************************************************************************************************/

CONSTANTS
{
  zero_start = 0xffff8000
}

MEMORY
{
	/* Bootmanager shared data: 0x00003C00 to 0x00003D00 */
	BOOTMGR_HWDESC        (R) : ORIGIN=0x00003C00, LENGTH=0x100

	/* Bootloader shared data: 0x00047800 to 0x00047FFF */
	BTLD_SWEDESC          (R) : ORIGIN=0x00047800, LENGTH=0x00000300
	BTLD_SWESTAT          (R) : ORIGIN=0x00047B00, LENGTH=0x00000300
	BTLD_SWESIG           (R) : ORIGIN=0x00047E00, LENGTH=0x00000200

	/* Application Interrupt Vector Region: From 0x00048000 to 0x000487FF */
	APPVECTOR             (RX) : ORIGIN=0x00048000, LENGTH=0x00000800

	/* Application Region: From 0x00048800 to 0x001BF7FF */
	APP_FLASH             (RX) : ORIGIN=0x00048800, LENGTH=0x00176FFC
	APP_CRC               (RX) : ORIGIN=0x001BF7FC, LENGTH=0x00000004

	/* Application SWE Data Region: From 0x001BF800 to 0x001BFFFF */
	APP_SWEDESC           (R) : ORIGIN=0x001BF800, LENGTH=0x00000300
	APP_SWESTAT           (R) : ORIGIN=0x001BFB00, LENGTH=0x00000300
	APP_SWESIG            (R) : ORIGIN=0x001BFE00, LENGTH=0x00000200

	/* Cal 1 Region: From 0x001C0000 to 0x001DFFFF */
	CAL1_FLASH            (RX) : ORIGIN= 0x001C0000, LENGTH=0x0001F7FC
	CAL1_CRC              (RX) : ORIGIN= 0x001DF7FC, LENGTH=0x00000004
	CAL1_SWEDESC          (R) : ORIGIN= 0x001DF800, LENGTH=0x00000300
	CAL1_SWESTAT          (R) : ORIGIN=0x001DFB00, LENGTH=0x00000300
	CAL1_SWESIG           (R) : ORIGIN= 0x001DFE00, LENGTH=0x00000200

	/* Cal 2 Region: From 0x001E0000 to 0x001FFFFF */
	CAL2_FLASH            (RX) : ORIGIN=0x001E0000, LENGTH=0x0001F7FC
	CAL2_CRC              (RX) : ORIGIN=0x001FF7FC, LENGTH=0x00000004
	CAL2_SWEDESC          (RX) : ORIGIN=0x001FF800, LENGTH=0x00000300
	CAL2_SWESTAT          (RX) : ORIGIN=0x001FFB00, LENGTH=0x00000300
	CAL2_SWESIG           (R) : ORIGIN=0x001FFE00, LENGTH= 0x00000200

	iROM_1         : ORIGIN = 0x01000000,  LENGTH = 32k
	iRAM_0         : ORIGIN = 0xFEBE0000,  LENGTH = 122k
	iRAM_SHAREDDATA : ORIGIN =0xFEBFE800, LENGTH = 2K
	iRAM_DMAWRITE  : ORIGIN = 0xFEBFF000,  LENGTH = 4k
 }

SECTIONS
 {
    /*--------------------------------------------------------------------------------------------------*/
    /*                            ROM Definitions                                                       */
    /*--------------------------------------------------------------------------------------------------*/
    .appstrtvect                  FILL(0xFF) :{*(.APPVECTOR) .= align(4);}>APPVECTOR /* Start of interrupt vector */
    .rozdata                      FILL(0xFF) :{*(.rozdata)   .= align(4);}>APP_FLASH /* Constant datas in ZDA area */
    .robase                       FILL(0xFF) :{*(.robase)    .= align(4);}>.         /* Initialize textpointer TP for SDA addressing */
    .rosdata                      FILL(0xFF) :{*(.rosdata)   .= align(4);}>.         /* Constant datas in SDA area */
    #define OS_LINK_INTVEC_CONST
    #define OS_LINK_EXCVEC_CONST
    #define OS_LINK_CONST
    #include "Os_Link_Core0.ld"
    #define OS_LINK_INTVEC_CONST
    #define OS_LINK_CONST
    #include "Os_Link.ld"

    .rodata                       FILL(0xFF) :{*(.rodata)      .= align(4);}>. /* Constant datas in normal area */
    .R_FDL_Const                  FILL(0xFF) :{*(.R_FDL_Const) .= align(4);}>. /* Constant datas in normal area */                                       /* constant datas in normal area */

    .text                         FILL(0xFF) :{*(.text)       .= align(4);}>. /* Program code area */
    .R_FDL_Text                   FILL(0xFF) :{*(.R_FDL_Text) .= align(4);}>. /* FDL code in ROM (used by MCAL)*/                                      

    #define OS_LINK_CODE
    #define OS_LINK_INTVEC_CODE
    #define OS_LINK_EXCVEC_CODE
    #define OS_LINK_CALLOUT_CODE
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_FAR
    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_NEAR
    #define OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_FAR
    #define OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE0_NEAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL7_NEAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL9_FAR	
    #define OS_LINK_VAR_TASK_TASK_100MS_APPL9_NEAR	
    #define OS_LINK_VAR_TASK_TASK_10MSBSW_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MSBSW_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL7_NEAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL8_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL8_NEAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL9_FAR	
    #define OS_LINK_VAR_TASK_TASK_10MS_APPL9_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MSA_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MSA_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MSB_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MSB_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MSTMPLMONR_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MSTMPLMONR_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL7_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL8_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL8_NEAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL9_FAR	
    #define OS_LINK_VAR_TASK_TASK_2MS_APPL9_NEAR	
    #define OS_LINK_VAR_TASK_TASK_4MSBSW_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_4MSBSW_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_CODING_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_CODING_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_4MS_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_4MS_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_4MS_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_4MS_APPL7_NEAR	
    #define OS_LINK_VAR_TASK_TASK_5MSBSW_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_5MSBSW_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_COMBSW_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_COMBSW_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_INITBSW_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_INITBSW_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL10_FAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL10_NEAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL7_FAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL7_NEAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL8_FAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL8_NEAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL9_FAR	
    #define OS_LINK_VAR_TASK_TASK_INIT_APPL9_NEAR	
    #define OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_FAR	
    #define OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_NEAR	
    #define OS_LINK_VAR_ISR_FR_IRQLINE0_FAR	
    #define OS_LINK_VAR_ISR_FR_IRQLINE0_NEAR	
    #define OS_LINK_VAR_ISR_FR_IRQTIMER0_FAR	
    #define OS_LINK_VAR_ISR_FR_IRQTIMER0_NEAR	
    #define OS_LINK_VAR_ISR_MCU_ECM_EIC_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_MCU_ECM_EIC_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIC_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIC_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIRE_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIRE_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIR_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIG0_TIR_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIC_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIC_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIRE_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIRE_CAT2_ISR_NEAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR	
    #define OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR	
    #include "Os_Link_Core0.ld"

    #define OS_LINK_CODE
    #define OS_LINK_INTVEC_CODE
    #define OS_LINK_CALLOUT_CODE
    #include "Os_Link.ld"

	    SHAREDSWEDATA :{}>.
    
    .fixaddr        FILL(0xFF) :{*(.fixaddr) .=align(4);}>. /* ghs internal (compiler) */
    .fixtype        FILL(0xFF) :{*(.fixtype) .=align(4);}>. /* ghs internal (compiler) */
    .secinfo        FILL(0xFF) :{*(.secinfo) .=align(4);}>. /* ghs internal (runtime library) */
    .syscall        FILL(0xFF) :{*(.syscall) .=align(4);}>. /* ghs internal (linker) */

    .calflash_rodata   FILL(0xFF) :>.
    .calflash_rosdata  FILL(0xFF) :>.

    .romdata                    ROM(.data)          FILL(0xFF) :{}>. /* Constant data to initialize variables (copied to RAM at startup)*/
    .romzdata                   ROM(.zdata)         FILL(0xFF) :{}>. /* Constant data to initialize variables in ZDA area (copied to RAM at startup)*/
    .romsdata                   ROM(.sdata)         FILL(0xFF) :{}>. /* Constant data to initialize variables in SDA area (copied to RAM at startup)*/
    .romtdata                   ROM(.tdata)         FILL(0xFF) :{}>. /* Constant data to initialize variables in TDA area (copied to RAM at startup)*/
    .romsldata                  ROM(.sldata)        FILL(0xFF) :{}>. /* Constant data to initialize variables in LSDA area (copied to GRAM at startup)*/
    .ROM_data_dma_128           ROM(.data_dma_128)  FILL(0xFF) :{}>.
    .ROM_sdata_dma_128          ROM(.sdata_dma_128) FILL(0xFF) :{}>.
    .ROM_DlogUDSAdapterInitData          ROM(.DlogUDSAdapterInitData) FILL(0xFF) :{}>.

    .ROM.FLS_PRIVATE_CODE_RAM           ROM(.FLS_PRIVATE_CODE_RAM)          FILL(0xFF)  :{}>. /* Added from Fls integration manual */
    .ROM_MCALERRHNDLG_PRIVATE_CODE_RAM  ROM(.MCALERRHNDLG_PRIVATE_CODE_RAM) FILL(0xFF)  :{}>. /* Added from McalErrHndlg integration manual */
		
	HWEDESC align(4) NOLOAD :> BOOTMGR_HWDESC
	
	BOOTSWEDESC align(4) NOLOAD     :> BTLD_SWEDESC
	BOOTSWESTAT align(4) NOLOAD     :> BTLD_SWESTAT
    BOOTSWESIGNATURE align(4) NOLOAD   :> BTLD_SWESIG
	
    SWE1DESC   align(4)      :> APP_SWEDESC
    SWE1STAT   align(4)       :> APP_SWESTAT
	SWE1SIGNATURE   align(4)  :> APP_SWESIG
	
    SWE2DESC   align(4)       :> CAL1_SWEDESC
    SWE2STAT   align(4)       :> CAL1_SWESTAT
	SWE2SIGNATURE   align(4)  :> CAL1_SWESIG
	
	SWE3DESC   align(4)       :> CAL2_SWEDESC
    SWE3STAT   align(4)       :> CAL2_SWESTAT
    SWE3SIGNATURE   align(4)  :> CAL2_SWESIG


    /*--------------------------------------------------------------------------------------------------*/
    /*                            Checksum Definitions                                                  */
    /*--------------------------------------------------------------------------------------------------*/
    .APPCRC    FILL(0xFF) align(4) :{*(.APPCRC) .= sizeof(APP_CRC);  } > APP_CRC
    .CAL1CRC    FILL(0xFF) align(4) :{*(.CAL1CRC) .= sizeof(CAL1_CRC); } > CAL1_CRC
    .CAL2CRC    FILL(0xFF) align(4) :{*(.CAL2CRC) .= sizeof(CAL2_CRC); } > CAL2_CRC
    .CAL2_FLASH    FILL(0xFF) align(4) :{*(.CAL2_FLASH) .= sizeof(CAL2_FLASH); } > CAL2_FLASH

 
  
    _CCT_Range_01_Start =  0x00048000;
    _CCT_Range_01_Length = 0x001777FC;
    _CCT_Range_01_BitAddrGran = 8;
    _CCT_Range_01_Category = 300;
    _CCT_Range_01_Algorithm = 14;
    _CCT_Range_01_Address = addr(APP_CRC); 
  
    _CCT_Range_02_Start =  0x001C0000;
    _CCT_Range_02_Length = 0x0001F7FC;
    _CCT_Range_02_BitAddrGran = 8;
    _CCT_Range_02_Category = 200;
    _CCT_Range_02_Algorithm = 14;
    _CCT_Range_02_Address = addr(CAL1_CRC);
    
    _CCT_Range_03_Start  = 0x001E0000;
    _CCT_Range_03_Length = 0x0001F7FC;
    _CCT_Range_03_BitAddrGran = 8;
    _CCT_Range_03_Category = 200;
    _CCT_Range_03_Algorithm = 14;
    _CCT_Range_03_Address = addr(CAL2_CRC);
    

    /* Start of internal User-Boot-ROM1 area (iROM_1) */
    .bcode      align(4) :>iROM_1 /* User defined segment for executable code located in user boot 1 area */
    .bconst     align(4) :>.      /* User defined segment for constant data located in user boot 1 area   */
    
    __top_of_iROM1 = MEMENDADDR(iROM_1); /* Start of internal RAM area (iRAM) */
    .:>iRAM_0  /* initialized data */     /* Start of data area */

    _StackRam_StartAddr = .;
    #define OS_LINK_KERNEL_STACKS
    #include "Os_Link_Core0_Stacks.ld"
    _StackRam_EndAddr = .;
    _GeneralRam_StartAddr = .;
    
    .FLS_PRIVATE_CODE_RAM align(4)  :>. /* Fls integration manual */
    .MCALERRHNDLG_PRIVATE_CODE_RAM align(4)  :>.
    
    .data       align(4) :>. /* initialized data */
    _clearedRamStart = addr(.data);
    .sldata     align(4) :>. /* User defined segment for initialized data */
    .slbss      align(4) :>. /* User defined segment for initialized data */
    .bss        align(4) :>. /* Zero initialized data*/

    #define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0
    #include "Os_Link_Core0.ld"

    #define OS_LINK_VAR_APP_APPL0
    #include "Os_Link_Core0.ld"

    #define OS_LINK_VAR_APP_APPL10
	#include "Os_Link_Core0.ld"
	.OmcData  :{Omc_NvMAdapter.o(.sbss)}
	.DlogUDSAdapterUninitData  :{Dlog_UDSAdapter.o (.sbss)}
	.DlogUDSAdapterInitData  :{Dlog_UDSAdapter.o (.sdata)}
	_ModifiedEndAddrForBAC_Appl10 = .;
	
    #define OS_LINK_VAR_APP_APPL9
    #include "Os_Link_Core0.ld"	
	
    #define OS_LINK_VAR_APP_APPL8
    #include "Os_Link_Core0.ld"	
	
    #define OS_LINK_VAR_APP_APPL7
    #include "Os_Link_Core0.ld"	
	
    #define OS_LINK_VAR_APP_APPL6
    #include "Os_Link_Core0.ld"		
	
    #define OS_LINK_VAR_KERNEL
    #define OS_LINK_KERNEL_BARRIERS
    #define OS_LINK_KERNEL_CORESTATUS
    #include "Os_Link_Core0.ld"

    #define OS_LINK_VAR_GLOBALSHARED
    #include "Os_Link.ld"
    
    #define OS_LINK_VAR_KERNEL
    #include "Os_Link.ld"

    .sdabase        align(4)                  :>. /* initialize globalpointer GP for SDA addressing */
    .sdata          align(4)                  :>. /* initialized data in SDA area*/
    .sbss           align(4)                  :>. /* zero initialized data in SDA area*/
    .zdata          align(4)                  :>. /* initialized data in ZDA area*/
    .zbss           align(4)                  :>. /* zero initialized data in ZDA area*/
    .tdata          align(4) MAX_SIZE(0x0100) :>. /* initialized and zero-initialized data in TDA area */

    /* Stack */
    .ram_stack_start    align(4) :>. /* Start of stack area */
    
    _ram_stack_start = addr(.ram_stack_start);
    .stack              align(4) pad(0x0800) :>. /* definition of stack size */
    .ram_stack_end      align(4)             :>. /* End of stack area */
    
    _osSystemStack_c0_EndAddr = .; // Temp added
    
    _ram_stack_end = addr(.ram_stack_end);
    _clearedRamEnd = .;
    
    .heapbase           align(4)             :>.
    .heap               align(4)
            pad(endaddr(iRAM_0)-addr(.heapbase))
            NOCLEAR :>. /* definition of heap size */ 


    .CalRegn01 :>CAL1_FLASH
    .CalRegn02 :>CAL2_FLASH

    __top_of_iRAM_0 = MEMENDADDR( iRAM_0);

    .data_dma_128           :>iRAM_DMAWRITE
    .sdata_dma_128          :>.
    _GeneralRam_EndAddr = 0xFEBFFFFF;



    _RESET_CORE0 = 0;

    /*  Symbols for compiler references */
    ___ghs_romstart   = MEMADDR(APPVECTOR);
    ___ghs_romend     = 0x1FFFFF;

    ___ghs_ramstart   = MEMADDR(iRAM_0);
    ___ghs_ramend     = MEMENDADDR(iRAM_0);
	
	BOOTSTATUS          align(4)    :>iRAM_SHAREDDATA
	DLOG_SWESTATUS      align(4) NOCLEAR   :>.
 }

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/
