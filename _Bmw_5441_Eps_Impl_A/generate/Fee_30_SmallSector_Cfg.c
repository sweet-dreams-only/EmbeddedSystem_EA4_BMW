#define FEE_30_SMALLSECTOR_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fee_30_SmallSector.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (FEE_30_SMALLSECTOR_CFG_MAJOR_VERSION != (2u)) \
     || (FEE_30_SMALLSECTOR_CFG_MINOR_VERSION != (0u)))
# error "Version numbers of Fee_30_SmallSector_Cfg.c and Fee_30_SmallSector_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#define FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_DatasetSelectionBits = (1U);

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 686 PARTITIONLIST */ /* MD_FEE_30_SMALLSECTOR_9.2 */
CONST(Fee_30_SmallSector_PartitionConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_PartitionConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_PARTITIONS] = 
{
   /*  FEE0  */ {
     /*  Partition Start Address  */ 0x00000000UL, 
     /*  Partition Address Alignment  */ 0x0040U, 
     /*  Partition Write Alignment  */ 0x0004U, 
     /*  Partition Read Alignment  */ 0x0001U, 
     /*  FLS Device Index  */ 0x0000U, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFU, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
       /*  FeeBlockConfiguration  */ 0x0002U, 
       /*  FeeDemStatusDataBlock  */ 0x0006U, 
       /*  FeeDemAdminDataBlock  */ 0x0004U, 
       /*  FeeDemPrimaryDataBlock0  */ 0x0008U, 
       /*  FeeRte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl  */ 0x0070U, 
       /*  FeeDemPrimaryDataBlock1  */ 0x000AU, 
       /*  FeeRte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl  */ 0x0072U, 
       /*  FeeDemPrimaryDataBlock2  */ 0x000CU, 
       /*  FeeRte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC  */ 0x0074U, 
       /*  FeeDemPrimaryDataBlock3  */ 0x000EU, 
       /*  FeeRte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC  */ 0x0076U, 
       /*  FeeDemPrimaryDataBlock4  */ 0x0010U, 
       /*  Fee_NVM_BLOCK_DCM_ROE  */ 0x0078U, 
       /*  FeeDemPrimaryDataBlock5  */ 0x0012U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_CcaHwPartNr  */ 0x007AU, 
       /*  FeeDemPrimaryDataBlock6  */ 0x0014U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_CcaSerlNr  */ 0x007CU, 
       /*  FeeDemPrimaryDataBlock7  */ 0x0016U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_DiRestore  */ 0x007EU, 
       /*  FeeDemSecondaryDataBlock0  */ 0x0018U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_EpsSysSerlNr  */ 0x0080U, 
       /*  FeeDemSecondaryDataBlock1  */ 0x001AU, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr  */ 0x0084U, 
       /*  FeeDemSecondaryDataBlock2  */ 0x001CU, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf0  */ 0x0086U, 
       /*  FeeDemSecondaryDataBlock3  */ 0x001EU, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf1  */ 0x0088U, 
       /*  FeeDemSecondaryDataBlock5  */ 0x0020U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf2  */ 0x008AU, 
       /*  FeeDemSecondaryDataBlock6  */ 0x0022U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf3  */ 0x008CU, 
       /*  FeeDemSecondaryDataBlock7  */ 0x0024U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_MfgTmpBuf4  */ 0x008EU, 
       /*  FeeDemSecondaryDataBlock8  */ 0x0026U, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_SeedKey  */ 0x0090U, 
       /*  FeeDemSecondaryDataBlock9  */ 0x0028U, 
       /*  FeeRte_NvmBlock_PolarityCfg_PolarityCfgSaved  */ 0x0092U, 
       /*  FeeDemSecondaryDataBlock10  */ 0x002AU, 
       /*  FeeRte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf  */ 0x0094U, 
       /*  FeeDemSecondaryDataBlock11  */ 0x002CU, 
       /*  FeeRte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock  */ 0x0096U, 
       /*  FeeDemSecondaryDataBlock12  */ 0x002EU, 
       /*  FeeRte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock  */ 0x0098U, 
       /*  FeeDemSecondaryDataBlock13  */ 0x0030U, 
       /*  FeeRte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock  */ 0x009AU, 
       /*  FeeDemSecondaryDataBlock14  */ 0x0032U, 
       /*  FeeRte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock  */ 0x009CU, 
       /*  FeeDemSecondaryDataBlock15  */ 0x0034U, 
       /*  FeeRte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt  */ 0x009EU, 
       /*  FeeDemSecondaryDataBlock16  */ 0x0036U, 
       /*  FeeRte_NvmBlock_MotTqCmdSca_MotTqScaFac  */ 0x00A2U, 
       /*  FeeDemSecondaryDataBlock17  */ 0x0038U, 
       /*  FeeRte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom  */ 0x00A4U, 
       /*  FeeDemSecondaryDataBlock18  */ 0x003AU, 
       /*  FeeRte_NvmBlock_Vin  */ 0x00A6U, 
       /*  FeeDemSecondaryDataBlock19  */ 0x003CU, 
       /*  FeeRte_NvmBlock_Omc  */ 0x00A8U, 
       /*  FeeDemSecondaryDataBlock20  */ 0x003EU, 
       /*  FeeDemSecondaryDataBlock21  */ 0x0040U, 
       /*  Fee_NVM_BLOCK_BOOT_PROG_COUNTER  */ 0x00AAU, 
       /*  FeeDemSecondaryDataBlock22  */ 0x0042U, 
       /*  Fee_NVM_BLOCK_BOOT_PROG_DATA  */ 0x00ACU, 
       /*  FeeDemSecondaryDataBlock23  */ 0x0044U, 
       /*  Fee_NVM_BLOCK_BOOT_SVK_HISTORY  */ 0x00AEU, 
       /*  FeeDemSecondaryDataBlock24  */ 0x0046U, 
       /*  Fee_NVM_BLOCK_DLOG_SVK_SYS_SUPP  */ 0x00B0U, 
       /*  FeeDemSecondaryDataBlock25  */ 0x0048U, 
       /*  Fee_NVM_BLOCK_DLOG_SVK_PLANT  */ 0x00B2U, 
       /*  FeeDemSecondaryDataBlock26  */ 0x004AU, 
       /*  FeeDemSecondaryDataBlock27  */ 0x004CU, 
       /*  FeeDemSecondaryDataBlock28  */ 0x004EU, 
       /*  FeeDemSecondaryDataBlock29  */ 0x0050U, 
       /*  FeeRte_NvmBlock_Darh_ErrorQueue  */ 0x00B4U, 
       /*  FeeDemSecondaryDataBlock30  */ 0x0052U, 
       /*  FeeRte_NvmBlock_SysFricLrng_FricNonLrngData  */ 0x00B6U, 
       /*  FeeDemSecondaryDataBlock31  */ 0x0054U, 
       /*  FeeRte_NvmBlock_SysFricLrng_FricLrngData  */ 0x00B8U, 
       /*  FeeDemSecondaryDataBlock32  */ 0x0056U, 
       /*  FeeRte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs  */ 0x00BCU, 
       /*  FeeDemSecondaryDataBlock33  */ 0x0058U, 
       /*  FeeRte_NvmBlock_LrndRackCentr_LrndRackCentr  */ 0x00BEU, 
       /*  FeeDemSecondaryDataBlock34  */ 0x005AU, 
       /*  FeeDemSecondaryDataBlock35  */ 0x005CU, 
       /*  FeeDemSecondaryDataBlock36  */ 0x005EU, 
       /*  FeeDemSecondaryDataBlock37  */ 0x0060U, 
       /*  FeeDemSecondaryDataBlock38  */ 0x0062U, 
       /*  FeeDemSecondaryDataBlock39  */ 0x0064U, 
       /*  FeeDemSecondaryDataBlock4  */ 0x0066U, 
       /*  FeeRte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk  */ 0x0068U, 
       /*  FeeRte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry  */ 0x006AU, 
       /*  FeeRte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry  */ 0x006CU, 
       /*  FeeRte_NvmBlock_DiagcMgr_DiagcMgrApplCrc  */ 0x006EU, 
       /*  FeeRte_NvmBlock_CmnMfgSrv_IgnCntr  */ 0x0082U, 
       /*  FeeRte_NvmBlock_DutyCycThermProtn_FilStVal  */ 0x00A0U, 
       /*  FeeRte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo  */ 0x00BAU, 
       /*  FeeRte_NvmBlock_ExcpnHndlg_McuDiagcData  */ 0x00C0U, 
       /*  FeeRte_NvmBlock_TEstimn_TFilStVal  */ 0x00C2U, 
       /*  Fee_NVM_BLOCK_DLOG_SVK_ENTRY  */ 0x00C4U, 
       /*  FeeRte_NvmBlock_Darh_DiagnoseMasterEnable  */ 0x00C6U, 
       /*  FeeRte_NvmBlock_Coding_CodingData  */ 0x00C8U, 
       /*  FeeRte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx  */ 0x00CAU, 
       /*  FeeRte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx  */ 0x00CCU, 
       /*  FeeRte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom  */ 0x00CEU, 
       /*  FeeRte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr  */ 0x00D0U, 
       /*  FeeRte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal  */ 0x00D2U, 
       /*  FeeRte_NvmBlock_BmwDiagcSrvHndlg_TestStamp  */ 0x00D4U, 
       /*  FeeBlockDescriptor  */ 0x00D6U
    }
  }, 
   /*  FEE1  */ {
     /*  Partition Start Address  */ 0x00008000UL, 
     /*  Partition Address Alignment  */ 0x0040U, 
     /*  Partition Write Alignment  */ 0x0004U, 
     /*  Partition Read Alignment  */ 0x0001U, 
     /*  FLS Device Index  */ 0x0000U, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFU, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
    }
  }
};
/* PRQA L: PARTITIONLIST */

/* BlockConfigList is sorted by BlockNumbers in ascending order */
CONST(Fee_30_SmallSector_BlockConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_BlockConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_BLOCKS] =
{
  {
     /*  Block Start Address  */ 0x00000000UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000000C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000080UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000100UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000240UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000380UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000440UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000500UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000580UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000600UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000680UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000700UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000780UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000800UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000880UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000900UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000980UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A00UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A80UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B00UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000BC0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000C80UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000D40UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000E00UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000EC0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000F80UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001000UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000010C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001180UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001200UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001280UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000012C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001340UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001400UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001480UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001540UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001600UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001640UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001680UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000016C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001740UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000017C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001900UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000019C0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001A80UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001AC0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001B00UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001B40UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001B80UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001BC0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001C00UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001C40UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001C80UL, 
     /*  Data Length  */ 0x0052U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001D00UL, 
     /*  Data Length  */ 0x0016U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001D40UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000140UL, 
     /*  Data Length  */ 0x006AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000280UL, 
     /*  Data Length  */ 0x006AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000003C0UL, 
     /*  Data Length  */ 0x000EU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000480UL, 
     /*  Data Length  */ 0x001EU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000540UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000005C0UL, 
     /*  Data Length  */ 0x0016U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000640UL, 
     /*  Data Length  */ 0x0016U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000006C0UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000740UL, 
     /*  Data Length  */ 0x0016U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001D80UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000007C0UL, 
     /*  Data Length  */ 0x0003U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000840UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000008C0UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000940UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000009C0UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A40UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000AC0UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B40UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000C00UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000CC0UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000D80UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000E40UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000F00UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000FC0UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001DC0UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001040UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001100UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000011C0UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001240UL, 
     /*  Data Length  */ 0x0002U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001300UL, 
     /*  Data Length  */ 0x0008U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001380UL, 
     /*  Data Length  */ 0x0030U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001440UL, 
     /*  Data Length  */ 0x000CU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000014C0UL, 
     /*  Data Length  */ 0x0039U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001580UL, 
     /*  Data Length  */ 0x0039U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001700UL, 
     /*  Data Length  */ 0x001EU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001780UL, 
     /*  Data Length  */ 0x000AU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001800UL, 
     /*  Data Length  */ 0x00DAU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001E00UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001940UL, 
     /*  Data Length  */ 0x0016U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001A00UL, 
     /*  Data Length  */ 0x000EU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001E40UL, 
     /*  Data Length  */ 0x0012U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001E80UL, 
     /*  Data Length  */ 0x0022U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001EC0UL, 
     /*  Data Length  */ 0x0038U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001FC0UL, 
     /*  Data Length  */ 0x0001U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002000UL, 
     /*  Data Length  */ 0x00A2U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000020C0UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002100UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002140UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002180UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000021C0UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002200UL, 
     /*  Data Length  */ 0x0005U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00002240UL, 
     /*  Data Length  */ 0x0006U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }
};
/* FLS API pointer table */
CONST(Fee_30_SmallSector_FlsApiType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_FlsApi0 = 
{
   /*  Read Service  */ Fls_Read, 
   /*  Write Service  */ Fls_Write, 
   /*  Compare Service  */ Fls_Compare, 
   /*  Erase Service  */ Fls_Erase, 
   /*  Blank Check Service  */ Fls_BlankCheck, 
   /*  Get Status Service  */ Fls_GetStatus, 
   /*  Get Job Result Service  */ Fls_GetJobResult
};
 

/**** NvM Callback Assignments ****/
CONST(Fee_30_SmallSector_CbkJobEndNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobEndNotification =
    NULL_PTR;
CONST(Fee_30_SmallSector_CbkJobErrorNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobErrorNotification =
    NULL_PTR;

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_FEE_30_SMALLSECTOR_9.2: rule 9.2
      Reason:     Array size of Fee_30_SmallSector_PartitionConfigType.BlockNumberList depends on maximum number of blocks in one partition.             
      Risk:       No risk. Partitions with fewer blocks and thus BlockNumberLists with fewer initializers are implicitly 
                  initialized to zero.
      Prevention: Program flow has been verified by component tests and review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_SmallSector_Cfg.c
 *********************************************************************************************************************/

