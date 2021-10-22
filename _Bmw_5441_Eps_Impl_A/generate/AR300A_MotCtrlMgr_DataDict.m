%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 30-Jul-2018 20:00:09       %
%                                  Created with tool release: 3.3.0      %
%                                  Synergy file: %version: 27 %           %
%                                  Derived by: %derived_by: tzyksv %          %
%%-----------------------------------------------------------------------%

AR300A = DataDict.FDD;
AR300A.Version = '1.0.X';
AR300A.LongName = 'Motor Control Manager';
AR300A.ShoName  = 'MotCtrlMgr';
AR300A.DesignASIL = 'D';
AR300A.Description = [...
  'This component handles runnable scheduling of MotorControl and MotorCo' ...
  'ntrolx2 runnables.  This also defines all of the Motor Control related' ...
  ' data and is resposible for the runnables providing the data interface' ...
  ' to the RTE.'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
MotCtrlMgrPer1 = DataDict.Runnable;
MotCtrlMgrPer1.Context = 'Rte';
MotCtrlMgrPer1.TimeStep = 0.002;
MotCtrlMgrPer1.Description = '';

MotCtrlMgrPer2 = DataDict.Runnable;
MotCtrlMgrPer2.Context = 'Rte';
MotCtrlMgrPer2.TimeStep = 0.002;
MotCtrlMgrPer2.Description = '';


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
DmaEna2MilliSecToMotCtrlTrf = DataDict.Client;
DmaEna2MilliSecToMotCtrlTrf.CallLocation = {'MotCtrlMgrPer2'};
DmaEna2MilliSecToMotCtrlTrf.Description = '';
DmaEna2MilliSecToMotCtrlTrf.Return = DataDict.CSReturn;
DmaEna2MilliSecToMotCtrlTrf.Return.Type = 'None';
DmaEna2MilliSecToMotCtrlTrf.Return.Min = [];
DmaEna2MilliSecToMotCtrlTrf.Return.Max = [];
DmaEna2MilliSecToMotCtrlTrf.Return.TestTolerance = [];


DmaWaitForMotCtrlTo2MilliSecTrf = DataDict.Client;
DmaWaitForMotCtrlTo2MilliSecTrf.CallLocation = {'MotCtrlMgrPer1'};
DmaWaitForMotCtrlTo2MilliSecTrf.Description = '';
DmaWaitForMotCtrlTo2MilliSecTrf.Return = DataDict.CSReturn;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Type = 'Standard';
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Min = 0;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Max = 1;
DmaWaitForMotCtrlTo2MilliSecTrf.Return.TestTolerance = [];
DmaWaitForMotCtrlTo2MilliSecTrf.Return.Description = '';



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
AdcDiagcEndPtrOutp = DataDict.IpSignal;
AdcDiagcEndPtrOutp.LongName = 'AdcDiagcEndPtrOutp';
AdcDiagcEndPtrOutp.Description = '';
AdcDiagcEndPtrOutp.DocUnits = 'Cnt';
AdcDiagcEndPtrOutp.EngDT = dt.u08;
AdcDiagcEndPtrOutp.EngInit = 23;
AdcDiagcEndPtrOutp.EngMin = 21;
AdcDiagcEndPtrOutp.EngMax = 23;
AdcDiagcEndPtrOutp.ReadIn = {'MotCtrlMgrPer2'};
AdcDiagcEndPtrOutp.ReadType = 'Rte';


AdcDiagcStrtPtrOutp = DataDict.IpSignal;
AdcDiagcStrtPtrOutp.LongName = 'AdcDiagcStrtPtrOutp';
AdcDiagcStrtPtrOutp.Description = '';
AdcDiagcStrtPtrOutp.DocUnits = 'Cnt';
AdcDiagcStrtPtrOutp.EngDT = dt.u08;
AdcDiagcStrtPtrOutp.EngInit = 21;
AdcDiagcStrtPtrOutp.EngMin = 21;
AdcDiagcStrtPtrOutp.EngMax = 23;
AdcDiagcStrtPtrOutp.ReadIn = {'MotCtrlMgrPer2'};
AdcDiagcStrtPtrOutp.ReadType = 'Rte';


BrdgVltg = DataDict.IpSignal;
BrdgVltg.LongName = 'BrdgVltg';
BrdgVltg.Description = '';
BrdgVltg.DocUnits = 'Volt';
BrdgVltg.EngDT = dt.float32;
BrdgVltg.EngInit = 6;
BrdgVltg.EngMin = 6;
BrdgVltg.EngMax = 26.5;
BrdgVltg.ReadIn = {'MotCtrlMgrPer2'};
BrdgVltg.ReadType = 'Rte';


CurrMeasCorrlnSts = DataDict.IpSignal;
CurrMeasCorrlnSts.LongName = 'CurrMeasCorrlnSts';
CurrMeasCorrlnSts.Description = '';
CurrMeasCorrlnSts.DocUnits = 'Cnt';
CurrMeasCorrlnSts.EngDT = dt.u08;
CurrMeasCorrlnSts.EngInit = 63;
CurrMeasCorrlnSts.EngMin = 0;
CurrMeasCorrlnSts.EngMax = 63;
CurrMeasCorrlnSts.ReadIn = {'MotCtrlMgrPer2'};
CurrMeasCorrlnSts.ReadType = 'Rte';


CurrMeasWrmIninTestCmpl = DataDict.IpSignal;
CurrMeasWrmIninTestCmpl.LongName = 'CurrMeasWrmIninTestCmpl';
CurrMeasWrmIninTestCmpl.Description = '';
CurrMeasWrmIninTestCmpl.DocUnits = 'Cnt';
CurrMeasWrmIninTestCmpl.EngDT = dt.lgc;
CurrMeasWrmIninTestCmpl.EngInit = 0;
CurrMeasWrmIninTestCmpl.EngMin = 0;
CurrMeasWrmIninTestCmpl.EngMax = 1;
CurrMeasWrmIninTestCmpl.ReadIn = {'MotCtrlMgrPer2'};
CurrMeasWrmIninTestCmpl.ReadType = 'Rte';


DiagcStsIvtr1Inactv = DataDict.IpSignal;
DiagcStsIvtr1Inactv.LongName = 'DiagcStsIvtr1Inactv';
DiagcStsIvtr1Inactv.Description = '';
DiagcStsIvtr1Inactv.DocUnits = 'Cnt';
DiagcStsIvtr1Inactv.EngDT = dt.lgc;
DiagcStsIvtr1Inactv.EngInit = 0;
DiagcStsIvtr1Inactv.EngMin = 0;
DiagcStsIvtr1Inactv.EngMax = 1;
DiagcStsIvtr1Inactv.ReadIn = {'MotCtrlMgrPer2'};
DiagcStsIvtr1Inactv.ReadType = 'Rte';


EcuTFild = DataDict.IpSignal;
EcuTFild.LongName = 'EcuTFild';
EcuTFild.Description = '';
EcuTFild.DocUnits = 'DegCgrd';
EcuTFild.EngDT = dt.float32;
EcuTFild.EngInit = 25;
EcuTFild.EngMin = -50;
EcuTFild.EngMax = 150;
EcuTFild.ReadIn = {'MotCtrlMgrPer2'};
EcuTFild.ReadType = 'Rte';


IvtrFetFltPha = DataDict.IpSignal;
IvtrFetFltPha.LongName = 'IvtrFetFltPha';
IvtrFetFltPha.Description = '';
IvtrFetFltPha.DocUnits = 'Cnt';
IvtrFetFltPha.EngDT = enum.IvtrFetFltPha1;
IvtrFetFltPha.EngInit = IvtrFetFltPha1.IVTRFETFLTPHA_NOPHASNGFETFLT;
IvtrFetFltPha.EngMin = 0;
IvtrFetFltPha.EngMax = 4;
IvtrFetFltPha.ReadIn = {'MotCtrlMgrPer2'};
IvtrFetFltPha.ReadType = 'Rte';


IvtrFetFltTyp = DataDict.IpSignal;
IvtrFetFltTyp.LongName = 'IvtrFetFltTyp';
IvtrFetFltTyp.Description = '';
IvtrFetFltTyp.DocUnits = 'Cnt';
IvtrFetFltTyp.EngDT = enum.IvtrFetFltTyp1;
IvtrFetFltTyp.EngInit = IvtrFetFltTyp1.IVTRFETFLTTYP_NOFETFLT;
IvtrFetFltTyp.EngMin = 0;
IvtrFetFltTyp.EngMax = 4;
IvtrFetFltTyp.ReadIn = {'MotCtrlMgrPer2'};
IvtrFetFltTyp.ReadType = 'Rte';


LoopCntr2MilliSec = DataDict.IpSignal;
LoopCntr2MilliSec.LongName = 'LoopCntr2MilliSec';
LoopCntr2MilliSec.Description = '';
LoopCntr2MilliSec.DocUnits = 'Cnt';
LoopCntr2MilliSec.EngDT = dt.u16;
LoopCntr2MilliSec.EngInit = 0;
LoopCntr2MilliSec.EngMin = 0;
LoopCntr2MilliSec.EngMax = 65535;
LoopCntr2MilliSec.ReadIn = {'MotCtrlMgrPer2'};
LoopCntr2MilliSec.ReadType = 'Rte';


MotAg0QepFaild = DataDict.IpSignal;
MotAg0QepFaild.LongName = 'MotAg0QepFaild';
MotAg0QepFaild.Description = '';
MotAg0QepFaild.DocUnits = 'Cnt';
MotAg0QepFaild.EngDT = dt.lgc;
MotAg0QepFaild.EngInit = 0;
MotAg0QepFaild.EngMin = 0;
MotAg0QepFaild.EngMax = 1;
MotAg0QepFaild.ReadIn = {'MotCtrlMgrPer2'};
MotAg0QepFaild.ReadType = 'Rte';


MotAg1QepFaild = DataDict.IpSignal;
MotAg1QepFaild.LongName = 'MotAg1QepFaild';
MotAg1QepFaild.Description = '';
MotAg1QepFaild.DocUnits = 'Cnt';
MotAg1QepFaild.EngDT = dt.lgc;
MotAg1QepFaild.EngInit = 0;
MotAg1QepFaild.EngMin = 0;
MotAg1QepFaild.EngMax = 1;
MotAg1QepFaild.ReadIn = {'MotCtrlMgrPer2'};
MotAg1QepFaild.ReadType = 'Rte';


MotAgElecDly = DataDict.IpSignal;
MotAgElecDly.LongName = 'MotAgElecDly';
MotAgElecDly.Description = '';
MotAgElecDly.DocUnits = 'MotRad';
MotAgElecDly.EngDT = dt.float32;
MotAgElecDly.EngInit = 0;
MotAgElecDly.EngMin = -1.5;
MotAgElecDly.EngMax = 1.5;
MotAgElecDly.ReadIn = {'MotCtrlMgrPer2'};
MotAgElecDly.ReadType = 'Rte';


MotAndThermProtnLoaMod = DataDict.IpSignal;
MotAndThermProtnLoaMod.LongName = 'MotAndThermProtnLoaMod';
MotAndThermProtnLoaMod.Description = '';
MotAndThermProtnLoaMod.DocUnits = 'Cnt';
MotAndThermProtnLoaMod.EngDT = dt.u08;
MotAndThermProtnLoaMod.EngInit = 0;
MotAndThermProtnLoaMod.EngMin = 0;
MotAndThermProtnLoaMod.EngMax = 7;
MotAndThermProtnLoaMod.ReadIn = {'MotCtrlMgrPer2'};
MotAndThermProtnLoaMod.ReadType = 'Rte';


MotBackEmfVltg = DataDict.IpSignal;
MotBackEmfVltg.LongName = 'MotBackEmfVltg';
MotBackEmfVltg.Description = '';
MotBackEmfVltg.DocUnits = 'Volt';
MotBackEmfVltg.EngDT = dt.float32;
MotBackEmfVltg.EngInit = 0;
MotBackEmfVltg.EngMin = -101.25;
MotBackEmfVltg.EngMax = 101.25;
MotBackEmfVltg.ReadIn = {'MotCtrlMgrPer2'};
MotBackEmfVltg.ReadType = 'Rte';


MotCurrAdcVlyAAdcFaild = DataDict.IpSignal;
MotCurrAdcVlyAAdcFaild.LongName = 'MotCurrAdcVlyAAdcFaild';
MotCurrAdcVlyAAdcFaild.Description = '';
MotCurrAdcVlyAAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyAAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyAAdcFaild.EngInit = 0;
MotCurrAdcVlyAAdcFaild.EngMin = 0;
MotCurrAdcVlyAAdcFaild.EngMax = 1;
MotCurrAdcVlyAAdcFaild.ReadIn = {'MotCtrlMgrPer2'};
MotCurrAdcVlyAAdcFaild.ReadType = 'Rte';


MotCurrAdcVlyBAdcFaild = DataDict.IpSignal;
MotCurrAdcVlyBAdcFaild.LongName = 'MotCurrAdcVlyBAdcFaild';
MotCurrAdcVlyBAdcFaild.Description = '';
MotCurrAdcVlyBAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyBAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyBAdcFaild.EngInit = 0;
MotCurrAdcVlyBAdcFaild.EngMin = 0;
MotCurrAdcVlyBAdcFaild.EngMax = 1;
MotCurrAdcVlyBAdcFaild.ReadIn = {'MotCtrlMgrPer2'};
MotCurrAdcVlyBAdcFaild.ReadType = 'Rte';


MotCurrAdcVlyCAdcFaild = DataDict.IpSignal;
MotCurrAdcVlyCAdcFaild.LongName = 'MotCurrAdcVlyCAdcFaild';
MotCurrAdcVlyCAdcFaild.Description = '';
MotCurrAdcVlyCAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyCAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyCAdcFaild.EngInit = 0;
MotCurrAdcVlyCAdcFaild.EngMin = 0;
MotCurrAdcVlyCAdcFaild.EngMax = 1;
MotCurrAdcVlyCAdcFaild.ReadIn = {'MotCtrlMgrPer2'};
MotCurrAdcVlyCAdcFaild.ReadType = 'Rte';


MotCurrDaxCmd = DataDict.IpSignal;
MotCurrDaxCmd.LongName = 'MotCurrDaxCmd';
MotCurrDaxCmd.Description = '';
MotCurrDaxCmd.DocUnits = 'Ampr';
MotCurrDaxCmd.EngDT = dt.float32;
MotCurrDaxCmd.EngInit = 0;
MotCurrDaxCmd.EngMin = 0;
MotCurrDaxCmd.EngMax = 220;
MotCurrDaxCmd.ReadIn = {'MotCtrlMgrPer2'};
MotCurrDaxCmd.ReadType = 'Rte';


MotCurrDaxMax = DataDict.IpSignal;
MotCurrDaxMax.LongName = 'MotCurrDaxMax';
MotCurrDaxMax.Description = '';
MotCurrDaxMax.DocUnits = 'Ampr';
MotCurrDaxMax.EngDT = dt.float32;
MotCurrDaxMax.EngInit = 0;
MotCurrDaxMax.EngMin = 0;
MotCurrDaxMax.EngMax = 220;
MotCurrDaxMax.ReadIn = {'MotCtrlMgrPer2'};
MotCurrDaxMax.ReadType = 'Rte';


MotCurrEolCalSt = DataDict.IpSignal;
MotCurrEolCalSt.LongName = 'MotCurrEolCalSt';
MotCurrEolCalSt.Description = '';
MotCurrEolCalSt.DocUnits = 'Cnt';
MotCurrEolCalSt.EngDT = enum.MotCurrEolCalSt2;
MotCurrEolCalSt.EngInit = MotCurrEolCalSt2.MCECS_OFFSCMDSTRT;
MotCurrEolCalSt.EngMin = 0;
MotCurrEolCalSt.EngMax = 8;
MotCurrEolCalSt.ReadIn = {'MotCtrlMgrPer2'};
MotCurrEolCalSt.ReadType = 'Rte';


MotCurrQaxCmd = DataDict.IpSignal;
MotCurrQaxCmd.LongName = 'MotCurrQaxCmd';
MotCurrQaxCmd.Description = '';
MotCurrQaxCmd.DocUnits = 'Ampr';
MotCurrQaxCmd.EngDT = dt.float32;
MotCurrQaxCmd.EngInit = 0;
MotCurrQaxCmd.EngMin = -220;
MotCurrQaxCmd.EngMax = 220;
MotCurrQaxCmd.ReadIn = {'MotCtrlMgrPer2'};
MotCurrQaxCmd.ReadType = 'Rte';


MotCurrQlfr1 = DataDict.IpSignal;
MotCurrQlfr1.LongName = 'MotCurrQlfr1';
MotCurrQlfr1.Description = '';
MotCurrQlfr1.DocUnits = 'Cnt';
MotCurrQlfr1.EngDT = enum.SigQlfr1;
MotCurrQlfr1.EngInit = SigQlfr1.SIGQLFR_NORES;
MotCurrQlfr1.EngMin = 0;
MotCurrQlfr1.EngMax = 2;
MotCurrQlfr1.ReadIn = {'MotCtrlMgrPer2'};
MotCurrQlfr1.ReadType = 'Rte';


MotDampgDax = DataDict.IpSignal;
MotDampgDax.LongName = 'MotDampgDax';
MotDampgDax.Description = '';
MotDampgDax.DocUnits = 'Ohm';
MotDampgDax.EngDT = dt.float32;
MotDampgDax.EngInit = 0;
MotDampgDax.EngMin = -0.11;
MotDampgDax.EngMax = 5.5;
MotDampgDax.ReadIn = {'MotCtrlMgrPer2'};
MotDampgDax.ReadType = 'Rte';


MotDampgQax = DataDict.IpSignal;
MotDampgQax.LongName = 'MotDampgQax';
MotDampgQax.Description = '';
MotDampgQax.DocUnits = 'Ohm';
MotDampgQax.EngDT = dt.float32;
MotDampgQax.EngInit = 0;
MotDampgQax.EngMin = -0.11;
MotDampgQax.EngMax = 5.5;
MotDampgQax.ReadIn = {'MotCtrlMgrPer2'};
MotDampgQax.ReadType = 'Rte';


MotElecMeclPolarity = DataDict.IpSignal;
MotElecMeclPolarity.LongName = 'MotElecMeclPolarity';
MotElecMeclPolarity.Description = '';
MotElecMeclPolarity.DocUnits = 'Uls';
MotElecMeclPolarity.EngDT = dt.s08;
MotElecMeclPolarity.EngInit = 1;
MotElecMeclPolarity.EngMin = -1;
MotElecMeclPolarity.EngMax = 1;
MotElecMeclPolarity.ReadIn = {'MotCtrlMgrPer2'};
MotElecMeclPolarity.ReadType = 'Rte';


MotInduDaxEstimdIvs = DataDict.IpSignal;
MotInduDaxEstimdIvs.LongName = 'MotInduDaxEstimdIvs';
MotInduDaxEstimdIvs.Description = '';
MotInduDaxEstimdIvs.DocUnits = 'IvsHenry';
MotInduDaxEstimdIvs.EngDT = dt.float32;
MotInduDaxEstimdIvs.EngInit = 8412;
MotInduDaxEstimdIvs.EngMin = 2440;
MotInduDaxEstimdIvs.EngMax = 33334;
MotInduDaxEstimdIvs.ReadIn = {'MotCtrlMgrPer2'};
MotInduDaxEstimdIvs.ReadType = 'Rte';


MotInduQaxEstimdIvs = DataDict.IpSignal;
MotInduQaxEstimdIvs.LongName = 'MotInduQaxEstimdIvs';
MotInduQaxEstimdIvs.Description = '';
MotInduQaxEstimdIvs.DocUnits = 'IvsHenry';
MotInduQaxEstimdIvs.EngDT = dt.float32;
MotInduQaxEstimdIvs.EngInit = 8412;
MotInduQaxEstimdIvs.EngMin = 2440;
MotInduQaxEstimdIvs.EngMax = 33334;
MotInduQaxEstimdIvs.ReadIn = {'MotCtrlMgrPer2'};
MotInduQaxEstimdIvs.ReadType = 'Rte';


MotIntglGainDax = DataDict.IpSignal;
MotIntglGainDax.LongName = 'MotIntglGainDax';
MotIntglGainDax.Description = '';
MotIntglGainDax.DocUnits = 'Ohm';
MotIntglGainDax.EngDT = dt.float32;
MotIntglGainDax.EngInit = 0;
MotIntglGainDax.EngMin = 0;
MotIntglGainDax.EngMax = 0.6;
MotIntglGainDax.ReadIn = {'MotCtrlMgrPer2'};
MotIntglGainDax.ReadType = 'Rte';


MotIntglGainQax = DataDict.IpSignal;
MotIntglGainQax.LongName = 'MotIntglGainQax';
MotIntglGainQax.Description = '';
MotIntglGainQax.DocUnits = 'Ohm';
MotIntglGainQax.EngDT = dt.float32;
MotIntglGainQax.EngInit = 0;
MotIntglGainQax.EngMin = 0;
MotIntglGainQax.EngMax = 0.6;
MotIntglGainQax.ReadIn = {'MotCtrlMgrPer2'};
MotIntglGainQax.ReadType = 'Rte';


MotPropGainDax = DataDict.IpSignal;
MotPropGainDax.LongName = 'MotPropGainDax';
MotPropGainDax.Description = '';
MotPropGainDax.DocUnits = 'Ohm';
MotPropGainDax.EngDT = dt.float32;
MotPropGainDax.EngInit = 0;
MotPropGainDax.EngMin = 0;
MotPropGainDax.EngMax = 2.25;
MotPropGainDax.ReadIn = {'MotCtrlMgrPer2'};
MotPropGainDax.ReadType = 'Rte';


MotPropGainQax = DataDict.IpSignal;
MotPropGainQax.LongName = 'MotPropGainQax';
MotPropGainQax.Description = '';
MotPropGainQax.DocUnits = 'Ohm';
MotPropGainQax.EngDT = dt.float32;
MotPropGainQax.EngInit = 0;
MotPropGainQax.EngMin = 0;
MotPropGainQax.EngMax = 2.25;
MotPropGainQax.ReadIn = {'MotCtrlMgrPer2'};
MotPropGainQax.ReadType = 'Rte';


MotREstimd = DataDict.IpSignal;
MotREstimd.LongName = 'MotREstimd';
MotREstimd.Description = '';
MotREstimd.DocUnits = 'Ohm';
MotREstimd.EngDT = dt.float32;
MotREstimd.EngInit = 0.005;
MotREstimd.EngMin = 0.005;
MotREstimd.EngMax = 0.12565;
MotREstimd.ReadIn = {'MotCtrlMgrPer2'};
MotREstimd.ReadType = 'Rte';


MotReacncDax = DataDict.IpSignal;
MotReacncDax.LongName = 'MotReacncDax';
MotReacncDax.Description = '';
MotReacncDax.DocUnits = 'Ohm';
MotReacncDax.EngDT = dt.float32;
MotReacncDax.EngInit = 0;
MotReacncDax.EngMin = -2.87607;
MotReacncDax.EngMax = 2.87607;
MotReacncDax.ReadIn = {'MotCtrlMgrPer2'};
MotReacncDax.ReadType = 'Rte';


MotReacncQax = DataDict.IpSignal;
MotReacncQax.LongName = 'MotReacncQax';
MotReacncQax.Description = '';
MotReacncQax.DocUnits = 'Ohm';
MotReacncQax.EngDT = dt.float32;
MotReacncQax.EngInit = 0;
MotReacncQax.EngMin = -2.87607;
MotReacncQax.EngMax = 2.87607;
MotReacncQax.ReadIn = {'MotCtrlMgrPer2'};
MotReacncQax.ReadType = 'Rte';


MotVelMrf = DataDict.IpSignal;
MotVelMrf.LongName = 'MotVelMrf';
MotVelMrf.Description = '';
MotVelMrf.DocUnits = 'MotRadPerSec';
MotVelMrf.EngDT = dt.float32;
MotVelMrf.EngInit = 0;
MotVelMrf.EngMin = -1350;
MotVelMrf.EngMax = 1350;
MotVelMrf.ReadIn = {'MotCtrlMgrPer2'};
MotVelMrf.ReadType = 'Rte';


MotVltgDaxFf = DataDict.IpSignal;
MotVltgDaxFf.LongName = 'MotVltgDaxFf';
MotVltgDaxFf.Description = '';
MotVltgDaxFf.DocUnits = 'Volt';
MotVltgDaxFf.EngDT = dt.float32;
MotVltgDaxFf.EngInit = 0;
MotVltgDaxFf.EngMin = -26.5;
MotVltgDaxFf.EngMax = 26.5;
MotVltgDaxFf.ReadIn = {'MotCtrlMgrPer2'};
MotVltgDaxFf.ReadType = 'Rte';


MotVltgQaxFf = DataDict.IpSignal;
MotVltgQaxFf.LongName = 'MotVltgQaxFf';
MotVltgQaxFf.Description = '';
MotVltgQaxFf.DocUnits = 'Volt';
MotVltgQaxFf.EngDT = dt.float32;
MotVltgQaxFf.EngInit = 0;
MotVltgQaxFf.EngMin = -101.25;
MotVltgQaxFf.EngMax = 101.25;
MotVltgQaxFf.ReadIn = {'MotCtrlMgrPer2'};
MotVltgQaxFf.ReadType = 'Rte';


PhaDiscnctDiagcActv = DataDict.IpSignal;
PhaDiscnctDiagcActv.LongName = 'PhaDiscnctDiagcActv';
PhaDiscnctDiagcActv.Description = '';
PhaDiscnctDiagcActv.DocUnits = 'Cnt';
PhaDiscnctDiagcActv.EngDT = dt.lgc;
PhaDiscnctDiagcActv.EngInit = 0;
PhaDiscnctDiagcActv.EngMin = 0;
PhaDiscnctDiagcActv.EngMax = 1;
PhaDiscnctDiagcActv.ReadIn = {'MotCtrlMgrPer2'};
PhaDiscnctDiagcActv.ReadType = 'Rte';


PhaDiscnctDiagcPwmVect = DataDict.IpSignal;
PhaDiscnctDiagcPwmVect.LongName = 'PhaDiscnctDiagcPwmVect';
PhaDiscnctDiagcPwmVect.Description = '';
PhaDiscnctDiagcPwmVect.DocUnits = 'Cnt';
PhaDiscnctDiagcPwmVect.EngDT = enum.PhaDiscnctPwmVect1;
PhaDiscnctDiagcPwmVect.EngInit = PhaDiscnctPwmVect1.PHADISCNCTPWMVECT_NOCMD;
PhaDiscnctDiagcPwmVect.EngMin = 0;
PhaDiscnctDiagcPwmVect.EngMax = 4;
PhaDiscnctDiagcPwmVect.ReadIn = {'MotCtrlMgrPer2'};
PhaDiscnctDiagcPwmVect.ReadType = 'Rte';


SysSt = DataDict.IpSignal;
SysSt.LongName = 'SysSt';
SysSt.Description = '';
SysSt.DocUnits = 'Cnt';
SysSt.EngDT = enum.SysSt1;
SysSt.EngInit = SysSt1.SYSST_WRMININ;
SysSt.EngMin = 0;
SysSt.EngMax = 3;
SysSt.ReadIn = {'MotCtrlMgrPer2'};
SysSt.ReadType = 'Rte';


VehSpd = DataDict.IpSignal;
VehSpd.LongName = 'VehSpd';
VehSpd.Description = '';
VehSpd.DocUnits = 'Kph';
VehSpd.EngDT = dt.float32;
VehSpd.EngInit = 0;
VehSpd.EngMin = 0;
VehSpd.EngMax = 511;
VehSpd.ReadIn = {'MotCtrlMgrPer2'};
VehSpd.ReadType = 'Rte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
Adc0ScanGroup2Ref0 = DataDict.OpSignal;
Adc0ScanGroup2Ref0.LongName = 'Adc0ScanGroup2Ref0';
Adc0ScanGroup2Ref0.Description = 'Adc0ScanGroup2Ref0';
Adc0ScanGroup2Ref0.DocUnits = 'Volt';
Adc0ScanGroup2Ref0.SwcShoName = 'MotCtrlMgr';
Adc0ScanGroup2Ref0.EngDT = dt.float32;
Adc0ScanGroup2Ref0.EngInit = 0;
Adc0ScanGroup2Ref0.EngMin = 0;
Adc0ScanGroup2Ref0.EngMax = 5;
Adc0ScanGroup2Ref0.TestTolerance = 0;
Adc0ScanGroup2Ref0.WrittenIn = {'MotCtrlMgrPer1'};
Adc0ScanGroup2Ref0.WriteType = 'Rte';


Adc0ScanGroup2Ref1 = DataDict.OpSignal;
Adc0ScanGroup2Ref1.LongName = 'Adc0ScanGroup2Ref1';
Adc0ScanGroup2Ref1.Description = 'Adc0ScanGroup2Ref1';
Adc0ScanGroup2Ref1.DocUnits = 'Volt';
Adc0ScanGroup2Ref1.SwcShoName = 'MotCtrlMgr';
Adc0ScanGroup2Ref1.EngDT = dt.float32;
Adc0ScanGroup2Ref1.EngInit = 0;
Adc0ScanGroup2Ref1.EngMin = 0;
Adc0ScanGroup2Ref1.EngMax = 5;
Adc0ScanGroup2Ref1.TestTolerance = 0;
Adc0ScanGroup2Ref1.WrittenIn = {'MotCtrlMgrPer1'};
Adc0ScanGroup2Ref1.WriteType = 'Rte';


Adc0ScanGroup3Ref0 = DataDict.OpSignal;
Adc0ScanGroup3Ref0.LongName = 'Adc0ScanGroup3Ref0';
Adc0ScanGroup3Ref0.Description = 'Adc0ScanGroup3Ref0';
Adc0ScanGroup3Ref0.DocUnits = 'Volt';
Adc0ScanGroup3Ref0.SwcShoName = 'MotCtrlMgr';
Adc0ScanGroup3Ref0.EngDT = dt.float32;
Adc0ScanGroup3Ref0.EngInit = 0;
Adc0ScanGroup3Ref0.EngMin = 0;
Adc0ScanGroup3Ref0.EngMax = 5;
Adc0ScanGroup3Ref0.TestTolerance = 0;
Adc0ScanGroup3Ref0.WrittenIn = {'MotCtrlMgrPer1'};
Adc0ScanGroup3Ref0.WriteType = 'Rte';


Adc0ScanGroup3Ref1 = DataDict.OpSignal;
Adc0ScanGroup3Ref1.LongName = 'Adc0ScanGroup3Ref1';
Adc0ScanGroup3Ref1.Description = 'Adc0ScanGroup3Ref1';
Adc0ScanGroup3Ref1.DocUnits = 'Volt';
Adc0ScanGroup3Ref1.SwcShoName = 'MotCtrlMgr';
Adc0ScanGroup3Ref1.EngDT = dt.float32;
Adc0ScanGroup3Ref1.EngInit = 0;
Adc0ScanGroup3Ref1.EngMin = 0;
Adc0ScanGroup3Ref1.EngMax = 5;
Adc0ScanGroup3Ref1.TestTolerance = 0;
Adc0ScanGroup3Ref1.WrittenIn = {'MotCtrlMgrPer1'};
Adc0ScanGroup3Ref1.WriteType = 'Rte';


Adc0SelfDiag0 = DataDict.OpSignal;
Adc0SelfDiag0.LongName = 'Adc0SelfDiag0';
Adc0SelfDiag0.Description = 'Adc0SelfDiag0';
Adc0SelfDiag0.DocUnits = 'Volt';
Adc0SelfDiag0.SwcShoName = 'MotCtrlMgr';
Adc0SelfDiag0.EngDT = dt.float32;
Adc0SelfDiag0.EngInit = 0;
Adc0SelfDiag0.EngMin = 0;
Adc0SelfDiag0.EngMax = 5;
Adc0SelfDiag0.TestTolerance = 0;
Adc0SelfDiag0.WrittenIn = {'MotCtrlMgrPer1'};
Adc0SelfDiag0.WriteType = 'Rte';


Adc0SelfDiag2 = DataDict.OpSignal;
Adc0SelfDiag2.LongName = 'Adc0SelfDiag2';
Adc0SelfDiag2.Description = 'Adc0SelfDiag2';
Adc0SelfDiag2.DocUnits = 'Volt';
Adc0SelfDiag2.SwcShoName = 'MotCtrlMgr';
Adc0SelfDiag2.EngDT = dt.float32;
Adc0SelfDiag2.EngInit = 0;
Adc0SelfDiag2.EngMin = 0;
Adc0SelfDiag2.EngMax = 5;
Adc0SelfDiag2.TestTolerance = 0;
Adc0SelfDiag2.WrittenIn = {'MotCtrlMgrPer1'};
Adc0SelfDiag2.WriteType = 'Rte';


Adc0SelfDiag4 = DataDict.OpSignal;
Adc0SelfDiag4.LongName = 'Adc0SelfDiag4';
Adc0SelfDiag4.Description = 'Adc0SelfDiag4';
Adc0SelfDiag4.DocUnits = 'Volt';
Adc0SelfDiag4.SwcShoName = 'MotCtrlMgr';
Adc0SelfDiag4.EngDT = dt.float32;
Adc0SelfDiag4.EngInit = 0;
Adc0SelfDiag4.EngMin = 0;
Adc0SelfDiag4.EngMax = 5;
Adc0SelfDiag4.TestTolerance = 0;
Adc0SelfDiag4.WrittenIn = {'MotCtrlMgrPer1'};
Adc0SelfDiag4.WriteType = 'Rte';


BattRtnCurrAdc = DataDict.OpSignal;
BattRtnCurrAdc.LongName = 'BattRtnCurrAdc';
BattRtnCurrAdc.Description = 'BattRtnCurrAdc';
BattRtnCurrAdc.DocUnits = 'Volt';
BattRtnCurrAdc.SwcShoName = 'MotCtrlMgr';
BattRtnCurrAdc.EngDT = dt.float32;
BattRtnCurrAdc.EngInit = 0;
BattRtnCurrAdc.EngMin = 0;
BattRtnCurrAdc.EngMax = 5;
BattRtnCurrAdc.TestTolerance = 0;
BattRtnCurrAdc.WrittenIn = {'MotCtrlMgrPer1'};
BattRtnCurrAdc.WriteType = 'Rte';


FastLoopCntr = DataDict.OpSignal;
FastLoopCntr.LongName = 'FastLoopCntr';
FastLoopCntr.Description = 'FastLoopCntr';
FastLoopCntr.DocUnits = 'Cnt';
FastLoopCntr.SwcShoName = 'MotCtrlMgr';
FastLoopCntr.EngDT = dt.u16;
FastLoopCntr.EngInit = 0;
FastLoopCntr.EngMin = 0;
FastLoopCntr.EngMax = 65535;
FastLoopCntr.TestTolerance = 0;
FastLoopCntr.WrittenIn = {'MotCtrlMgrPer1'};
FastLoopCntr.WriteType = 'Rte';


HwTq4RawAdc = DataDict.OpSignal;
HwTq4RawAdc.LongName = 'HwTq4RawAdc';
HwTq4RawAdc.Description = 'HwTq4RawAdc';
HwTq4RawAdc.DocUnits = 'Volt';
HwTq4RawAdc.SwcShoName = 'MotCtrlMgr';
HwTq4RawAdc.EngDT = dt.float32;
HwTq4RawAdc.EngInit = 0;
HwTq4RawAdc.EngMin = 0;
HwTq4RawAdc.EngMax = 5;
HwTq4RawAdc.TestTolerance = 0;
HwTq4RawAdc.WrittenIn = {'MotCtrlMgrPer1'};
HwTq4RawAdc.WriteType = 'Rte';


HwTq4RawFastAdcBuf = DataDict.OpSignal;
HwTq4RawFastAdcBuf.LongName = 'HwTq4RawFastAdcBuf';
HwTq4RawFastAdcBuf.Description = 'HwTq4RawFastAdcBuf';
HwTq4RawFastAdcBuf.DocUnits = 'Volt';
HwTq4RawFastAdcBuf.SwcShoName = 'MotCtrlMgr';
HwTq4RawFastAdcBuf.EngDT = dt.float32;
HwTq4RawFastAdcBuf.EngInit =  ...
   [0                0                0                0                0                0                0                0];
HwTq4RawFastAdcBuf.EngMin = 0;
HwTq4RawFastAdcBuf.EngMax = 5;
HwTq4RawFastAdcBuf.TestTolerance = 0;
HwTq4RawFastAdcBuf.WrittenIn = {'MotCtrlMgrPer1'};
HwTq4RawFastAdcBuf.WriteType = 'Rte';


HwTq5RawAdc = DataDict.OpSignal;
HwTq5RawAdc.LongName = 'HwTq5RawAdc';
HwTq5RawAdc.Description = 'HwTq5RawAdc';
HwTq5RawAdc.DocUnits = 'Volt';
HwTq5RawAdc.SwcShoName = 'MotCtrlMgr';
HwTq5RawAdc.EngDT = dt.float32;
HwTq5RawAdc.EngInit = 0;
HwTq5RawAdc.EngMin = 0;
HwTq5RawAdc.EngMax = 5;
HwTq5RawAdc.TestTolerance = 0;
HwTq5RawAdc.WrittenIn = {'MotCtrlMgrPer1'};
HwTq5RawAdc.WriteType = 'Rte';


HwTq5RawFastAdcBuf = DataDict.OpSignal;
HwTq5RawFastAdcBuf.LongName = 'HwTq5RawFastAdcBuf';
HwTq5RawFastAdcBuf.Description = 'HwTq5RawFastAdcBuf';
HwTq5RawFastAdcBuf.DocUnits = 'Volt';
HwTq5RawFastAdcBuf.SwcShoName = 'MotCtrlMgr';
HwTq5RawFastAdcBuf.EngDT = dt.float32;
HwTq5RawFastAdcBuf.EngInit =  ...
   [0                0                0                0                0                0                0                0];
HwTq5RawFastAdcBuf.EngMin = 0;
HwTq5RawFastAdcBuf.EngMax = 5;
HwTq5RawFastAdcBuf.TestTolerance = 0;
HwTq5RawFastAdcBuf.WrittenIn = {'MotCtrlMgrPer1'};
HwTq5RawFastAdcBuf.WriteType = 'Rte';


MotAg0ErrReg = DataDict.OpSignal;
MotAg0ErrReg.LongName = 'MotAg0ErrReg';
MotAg0ErrReg.Description = 'MotAg0ErrReg';
MotAg0ErrReg.DocUnits = 'Cnt';
MotAg0ErrReg.SwcShoName = 'MotCtrlMgr';
MotAg0ErrReg.EngDT = dt.u32;
MotAg0ErrReg.EngInit = 0;
MotAg0ErrReg.EngMin = 0;
MotAg0ErrReg.EngMax = 67108863;
MotAg0ErrReg.TestTolerance = 0;
MotAg0ErrReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0ErrReg.WriteType = 'Rte';


MotAg0ParFltCnt = DataDict.OpSignal;
MotAg0ParFltCnt.LongName = 'MotAg0ParFltCnt';
MotAg0ParFltCnt.Description = 'MotAg0ParFltCnt';
MotAg0ParFltCnt.DocUnits = 'Cnt';
MotAg0ParFltCnt.SwcShoName = 'MotCtrlMgr';
MotAg0ParFltCnt.EngDT = dt.u16;
MotAg0ParFltCnt.EngInit = 0;
MotAg0ParFltCnt.EngMin = 0;
MotAg0ParFltCnt.EngMax = 65535;
MotAg0ParFltCnt.TestTolerance = 0;
MotAg0ParFltCnt.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0ParFltCnt.WriteType = 'Rte';


MotAg0SpiMecl = DataDict.OpSignal;
MotAg0SpiMecl.LongName = 'MotAg0SpiMecl';
MotAg0SpiMecl.Description = 'MotAg0SpiMecl';
MotAg0SpiMecl.DocUnits = 'MotRev';
MotAg0SpiMecl.SwcShoName = 'MotCtrlMgr';
MotAg0SpiMecl.EngDT = dt.u16;
MotAg0SpiMecl.EngInit = 0;
MotAg0SpiMecl.EngMin = 0;
MotAg0SpiMecl.EngMax = 0.9999847412;
MotAg0SpiMecl.TestTolerance = 0;
MotAg0SpiMecl.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0SpiMecl.WriteType = 'Rte';


MotAg0TurnCntrReg = DataDict.OpSignal;
MotAg0TurnCntrReg.LongName = 'MotAg0TurnCntrReg';
MotAg0TurnCntrReg.Description = 'MotAg0TurnCntrReg';
MotAg0TurnCntrReg.DocUnits = 'Cnt';
MotAg0TurnCntrReg.SwcShoName = 'MotCtrlMgr';
MotAg0TurnCntrReg.EngDT = dt.u32;
MotAg0TurnCntrReg.EngInit = 0;
MotAg0TurnCntrReg.EngMin = 0;
MotAg0TurnCntrReg.EngMax = 67108863;
MotAg0TurnCntrReg.TestTolerance = 0;
MotAg0TurnCntrReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0TurnCntrReg.WriteType = 'Rte';


MotAg0VltgFltCnt = DataDict.OpSignal;
MotAg0VltgFltCnt.LongName = 'MotAg0VltgFltCnt';
MotAg0VltgFltCnt.Description = 'MotAg0VltgFltCnt';
MotAg0VltgFltCnt.DocUnits = 'Cnt';
MotAg0VltgFltCnt.SwcShoName = 'MotCtrlMgr';
MotAg0VltgFltCnt.EngDT = dt.u16;
MotAg0VltgFltCnt.EngInit = 0;
MotAg0VltgFltCnt.EngMin = 0;
MotAg0VltgFltCnt.EngMax = 65535;
MotAg0VltgFltCnt.TestTolerance = 0;
MotAg0VltgFltCnt.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0VltgFltCnt.WriteType = 'Rte';


MotAg0WarnReg = DataDict.OpSignal;
MotAg0WarnReg.LongName = 'MotAg0WarnReg';
MotAg0WarnReg.Description = 'MotAg0WarnReg';
MotAg0WarnReg.DocUnits = 'Cnt';
MotAg0WarnReg.SwcShoName = 'MotCtrlMgr';
MotAg0WarnReg.EngDT = dt.u32;
MotAg0WarnReg.EngInit = 0;
MotAg0WarnReg.EngMin = 0;
MotAg0WarnReg.EngMax = 67108863;
MotAg0WarnReg.TestTolerance = 0;
MotAg0WarnReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg0WarnReg.WriteType = 'Rte';


MotAg1ErrReg = DataDict.OpSignal;
MotAg1ErrReg.LongName = 'MotAg1ErrReg';
MotAg1ErrReg.Description = 'MotAg1ErrReg';
MotAg1ErrReg.DocUnits = 'Cnt';
MotAg1ErrReg.SwcShoName = 'MotCtrlMgr';
MotAg1ErrReg.EngDT = dt.u32;
MotAg1ErrReg.EngInit = 0;
MotAg1ErrReg.EngMin = 0;
MotAg1ErrReg.EngMax = 67108863;
MotAg1ErrReg.TestTolerance = 0;
MotAg1ErrReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1ErrReg.WriteType = 'Rte';


MotAg1ParFltCnt = DataDict.OpSignal;
MotAg1ParFltCnt.LongName = 'MotAg1ParFltCnt';
MotAg1ParFltCnt.Description = 'MotAg1ParFltCnt';
MotAg1ParFltCnt.DocUnits = 'Cnt';
MotAg1ParFltCnt.SwcShoName = 'MotCtrlMgr';
MotAg1ParFltCnt.EngDT = dt.u16;
MotAg1ParFltCnt.EngInit = 0;
MotAg1ParFltCnt.EngMin = 0;
MotAg1ParFltCnt.EngMax = 65535;
MotAg1ParFltCnt.TestTolerance = 0;
MotAg1ParFltCnt.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1ParFltCnt.WriteType = 'Rte';


MotAg1SpiMecl = DataDict.OpSignal;
MotAg1SpiMecl.LongName = 'MotAg1SpiMecl';
MotAg1SpiMecl.Description = 'MotAg1SpiMecl';
MotAg1SpiMecl.DocUnits = 'MotRev';
MotAg1SpiMecl.SwcShoName = 'MotCtrlMgr';
MotAg1SpiMecl.EngDT = dt.u16;
MotAg1SpiMecl.EngInit = 0;
MotAg1SpiMecl.EngMin = 0;
MotAg1SpiMecl.EngMax = 0.9999847412;
MotAg1SpiMecl.TestTolerance = 0;
MotAg1SpiMecl.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1SpiMecl.WriteType = 'Rte';


MotAg1TurnCntrReg = DataDict.OpSignal;
MotAg1TurnCntrReg.LongName = 'MotAg1TurnCntrReg';
MotAg1TurnCntrReg.Description = 'MotAg1TurnCntrReg';
MotAg1TurnCntrReg.DocUnits = 'Cnt';
MotAg1TurnCntrReg.SwcShoName = 'MotCtrlMgr';
MotAg1TurnCntrReg.EngDT = dt.u32;
MotAg1TurnCntrReg.EngInit = 0;
MotAg1TurnCntrReg.EngMin = 0;
MotAg1TurnCntrReg.EngMax = 67108863;
MotAg1TurnCntrReg.TestTolerance = 0;
MotAg1TurnCntrReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1TurnCntrReg.WriteType = 'Rte';


MotAg1VltgFltCnt = DataDict.OpSignal;
MotAg1VltgFltCnt.LongName = 'MotAg1VltgFltCnt';
MotAg1VltgFltCnt.Description = 'MotAg1VltgFltCnt';
MotAg1VltgFltCnt.DocUnits = 'Cnt';
MotAg1VltgFltCnt.SwcShoName = 'MotCtrlMgr';
MotAg1VltgFltCnt.EngDT = dt.u16;
MotAg1VltgFltCnt.EngInit = 0;
MotAg1VltgFltCnt.EngMin = 0;
MotAg1VltgFltCnt.EngMax = 65535;
MotAg1VltgFltCnt.TestTolerance = 0;
MotAg1VltgFltCnt.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1VltgFltCnt.WriteType = 'Rte';


MotAg1WarnReg = DataDict.OpSignal;
MotAg1WarnReg.LongName = 'MotAg1WarnReg';
MotAg1WarnReg.Description = 'MotAg1WarnReg';
MotAg1WarnReg.DocUnits = 'Cnt';
MotAg1WarnReg.SwcShoName = 'MotCtrlMgr';
MotAg1WarnReg.EngDT = dt.u32;
MotAg1WarnReg.EngInit = 0;
MotAg1WarnReg.EngMin = 0;
MotAg1WarnReg.EngMax = 67108863;
MotAg1WarnReg.TestTolerance = 0;
MotAg1WarnReg.WrittenIn = {'MotCtrlMgrPer1'};
MotAg1WarnReg.WriteType = 'Rte';


MotAg3Mecl = DataDict.OpSignal;
MotAg3Mecl.LongName = 'MotAg3Mecl';
MotAg3Mecl.Description = 'MotAg3Mecl';
MotAg3Mecl.DocUnits = 'MotRev';
MotAg3Mecl.SwcShoName = 'MotCtrlMgr';
MotAg3Mecl.EngDT = dt.u16;
MotAg3Mecl.EngInit = 0;
MotAg3Mecl.EngMin = 0;
MotAg3Mecl.EngMax = 0.9999847412;
MotAg3Mecl.TestTolerance = 0;
MotAg3Mecl.WrittenIn = {'MotCtrlMgrPer1'};
MotAg3Mecl.WriteType = 'Rte';


MotAg4Mecl = DataDict.OpSignal;
MotAg4Mecl.LongName = 'MotAg4Mecl';
MotAg4Mecl.Description = 'MotAg4Mecl';
MotAg4Mecl.DocUnits = 'MotRev';
MotAg4Mecl.SwcShoName = 'MotCtrlMgr';
MotAg4Mecl.EngDT = dt.u16;
MotAg4Mecl.EngInit = 0;
MotAg4Mecl.EngMin = 0;
MotAg4Mecl.EngMax = 0.9999847412;
MotAg4Mecl.TestTolerance = 0;
MotAg4Mecl.WrittenIn = {'MotCtrlMgrPer1'};
MotAg4Mecl.WriteType = 'Rte';


MotAgBuf = DataDict.OpSignal;
MotAgBuf.LongName = 'MotAgBuf';
MotAgBuf.Description = 'MotAgBuf';
MotAgBuf.DocUnits = 'MotRev';
MotAgBuf.SwcShoName = 'MotCtrlMgr';
MotAgBuf.EngDT = dt.u16;
MotAgBuf.EngInit =  ...
   [0                0                0                0                0                0                0                0];
MotAgBuf.EngMin = 0;
MotAgBuf.EngMax = 0.9999847412;
MotAgBuf.TestTolerance = 0;
MotAgBuf.WrittenIn = {'MotCtrlMgrPer1'};
MotAgBuf.WriteType = 'Rte';


MotAgBufIdx = DataDict.OpSignal;
MotAgBufIdx.LongName = 'MotAgBufIdx';
MotAgBufIdx.Description = 'MotAgBufIdx';
MotAgBufIdx.DocUnits = 'Cnt';
MotAgBufIdx.SwcShoName = 'MotCtrlMgr';
MotAgBufIdx.EngDT = dt.u08;
MotAgBufIdx.EngInit = 0;
MotAgBufIdx.EngMin = 0;
MotAgBufIdx.EngMax = 7;
MotAgBufIdx.TestTolerance = 0;
MotAgBufIdx.WrittenIn = {'MotCtrlMgrPer1'};
MotAgBufIdx.WriteType = 'Rte';


MotAgCumvAlgndMrfRev = DataDict.OpSignal;
MotAgCumvAlgndMrfRev.LongName = 'MotAgCumvAlgndMrfRev';
MotAgCumvAlgndMrfRev.Description = 'MotAgCumvAlgndMrfRev';
MotAgCumvAlgndMrfRev.DocUnits = 'MotRev';
MotAgCumvAlgndMrfRev.SwcShoName = 'MotCtrlMgr';
MotAgCumvAlgndMrfRev.EngDT = dt.s32;
MotAgCumvAlgndMrfRev.EngInit = 0;
MotAgCumvAlgndMrfRev.EngMin = -32768;
MotAgCumvAlgndMrfRev.EngMax = 32767.99998;
MotAgCumvAlgndMrfRev.TestTolerance = 0;
MotAgCumvAlgndMrfRev.WrittenIn = {'MotCtrlMgrPer1'};
MotAgCumvAlgndMrfRev.WriteType = 'Rte';


MotAgCumvInid = DataDict.OpSignal;
MotAgCumvInid.LongName = 'MotAgCumvInid';
MotAgCumvInid.Description = 'MotAgCumvInid';
MotAgCumvInid.DocUnits = 'Cnt';
MotAgCumvInid.SwcShoName = 'MotCtrlMgr';
MotAgCumvInid.EngDT = dt.lgc;
MotAgCumvInid.EngInit = 0;
MotAgCumvInid.EngMin = 0;
MotAgCumvInid.EngMax = 1;
MotAgCumvInid.TestTolerance = 0;
MotAgCumvInid.WrittenIn = {'MotCtrlMgrPer1'};
MotAgCumvInid.WriteType = 'Rte';


MotAgTiBuf = DataDict.OpSignal;
MotAgTiBuf.LongName = 'MotAgTiBuf';
MotAgTiBuf.Description = 'MotAgTiBuf';
MotAgTiBuf.DocUnits = 'MicroSec';
MotAgTiBuf.SwcShoName = 'MotCtrlMgr';
MotAgTiBuf.EngDT = dt.u32;
MotAgTiBuf.EngInit =  ...
   [0               62              125              187              250              312              375              437];
MotAgTiBuf.EngMin = 0;
MotAgTiBuf.EngMax = 4294967295;
MotAgTiBuf.TestTolerance = 0;
MotAgTiBuf.WrittenIn = {'MotCtrlMgrPer1'};
MotAgTiBuf.WriteType = 'Rte';


MotCurrAdcVlyA = DataDict.OpSignal;
MotCurrAdcVlyA.LongName = 'MotCurrAdcVlyA';
MotCurrAdcVlyA.Description = 'MotCurrAdcVlyA';
MotCurrAdcVlyA.DocUnits = 'Volt';
MotCurrAdcVlyA.SwcShoName = 'MotCtrlMgr';
MotCurrAdcVlyA.EngDT = dt.float32;
MotCurrAdcVlyA.EngInit = 0;
MotCurrAdcVlyA.EngMin = 0;
MotCurrAdcVlyA.EngMax = 5;
MotCurrAdcVlyA.TestTolerance = 0;
MotCurrAdcVlyA.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrAdcVlyA.WriteType = 'Rte';


MotCurrAdcVlyB = DataDict.OpSignal;
MotCurrAdcVlyB.LongName = 'MotCurrAdcVlyB';
MotCurrAdcVlyB.Description = 'MotCurrAdcVlyB';
MotCurrAdcVlyB.DocUnits = 'Volt';
MotCurrAdcVlyB.SwcShoName = 'MotCtrlMgr';
MotCurrAdcVlyB.EngDT = dt.float32;
MotCurrAdcVlyB.EngInit = 0;
MotCurrAdcVlyB.EngMin = 0;
MotCurrAdcVlyB.EngMax = 5;
MotCurrAdcVlyB.TestTolerance = 0;
MotCurrAdcVlyB.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrAdcVlyB.WriteType = 'Rte';


MotCurrAdcVlyC = DataDict.OpSignal;
MotCurrAdcVlyC.LongName = 'MotCurrAdcVlyC';
MotCurrAdcVlyC.Description = 'MotCurrAdcVlyC';
MotCurrAdcVlyC.DocUnits = 'Volt';
MotCurrAdcVlyC.SwcShoName = 'MotCtrlMgr';
MotCurrAdcVlyC.EngDT = dt.float32;
MotCurrAdcVlyC.EngInit = 0;
MotCurrAdcVlyC.EngMin = 0;
MotCurrAdcVlyC.EngMax = 5;
MotCurrAdcVlyC.TestTolerance = 0;
MotCurrAdcVlyC.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrAdcVlyC.WriteType = 'Rte';


MotCurrCorrdA = DataDict.OpSignal;
MotCurrCorrdA.LongName = 'MotCurrCorrdA';
MotCurrCorrdA.Description = 'MotCurrCorrdA';
MotCurrCorrdA.DocUnits = 'Ampr';
MotCurrCorrdA.SwcShoName = 'MotCtrlMgr';
MotCurrCorrdA.EngDT = dt.float32;
MotCurrCorrdA.EngInit = 0;
MotCurrCorrdA.EngMin = -200;
MotCurrCorrdA.EngMax = 200;
MotCurrCorrdA.TestTolerance = 0;
MotCurrCorrdA.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrCorrdA.WriteType = 'Rte';


MotCurrCorrdB = DataDict.OpSignal;
MotCurrCorrdB.LongName = 'MotCurrCorrdB';
MotCurrCorrdB.Description = 'MotCurrCorrdB';
MotCurrCorrdB.DocUnits = 'Ampr';
MotCurrCorrdB.SwcShoName = 'MotCtrlMgr';
MotCurrCorrdB.EngDT = dt.float32;
MotCurrCorrdB.EngInit = 0;
MotCurrCorrdB.EngMin = -200;
MotCurrCorrdB.EngMax = 200;
MotCurrCorrdB.TestTolerance = 0;
MotCurrCorrdB.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrCorrdB.WriteType = 'Rte';


MotCurrCorrdC = DataDict.OpSignal;
MotCurrCorrdC.LongName = 'MotCurrCorrdC';
MotCurrCorrdC.Description = 'MotCurrCorrdC';
MotCurrCorrdC.DocUnits = 'Ampr';
MotCurrCorrdC.SwcShoName = 'MotCtrlMgr';
MotCurrCorrdC.EngDT = dt.float32;
MotCurrCorrdC.EngInit = 0;
MotCurrCorrdC.EngMin = -200;
MotCurrCorrdC.EngMax = 200;
MotCurrCorrdC.TestTolerance = 0;
MotCurrCorrdC.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrCorrdC.WriteType = 'Rte';


MotCurrDax = DataDict.OpSignal;
MotCurrDax.LongName = 'MotCurrDax';
MotCurrDax.Description = 'MotCurrDax';
MotCurrDax.DocUnits = 'Ampr';
MotCurrDax.SwcShoName = 'MotCtrlMgr';
MotCurrDax.EngDT = dt.float32;
MotCurrDax.EngInit = 0;
MotCurrDax.EngMin = -200;
MotCurrDax.EngMax = 200;
MotCurrDax.TestTolerance = 0;
MotCurrDax.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrDax.WriteType = 'Rte';


MotCurrQax = DataDict.OpSignal;
MotCurrQax.LongName = 'MotCurrQax';
MotCurrQax.Description = 'MotCurrQax';
MotCurrQax.DocUnits = 'Ampr';
MotCurrQax.SwcShoName = 'MotCtrlMgr';
MotCurrQax.EngDT = dt.float32;
MotCurrQax.EngInit = 0;
MotCurrQax.EngMin = -200;
MotCurrQax.EngMax = 200;
MotCurrQax.TestTolerance = 0;
MotCurrQax.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrQax.WriteType = 'Rte';


MotCurrRollgCntr1 = DataDict.OpSignal;
MotCurrRollgCntr1.LongName = 'MotCurrRollgCntr1';
MotCurrRollgCntr1.Description = 'MotCurrRollgCntr1';
MotCurrRollgCntr1.DocUnits = 'Cnt';
MotCurrRollgCntr1.SwcShoName = 'MotCtrlMgr';
MotCurrRollgCntr1.EngDT = dt.u08;
MotCurrRollgCntr1.EngInit = 0;
MotCurrRollgCntr1.EngMin = 0;
MotCurrRollgCntr1.EngMax = 255;
MotCurrRollgCntr1.TestTolerance = 0;
MotCurrRollgCntr1.WrittenIn = {'MotCtrlMgrPer1'};
MotCurrRollgCntr1.WriteType = 'Rte';


MotVltgDax = DataDict.OpSignal;
MotVltgDax.LongName = 'MotVltgDax';
MotVltgDax.Description = 'MotVltgDax';
MotVltgDax.DocUnits = 'Volt';
MotVltgDax.SwcShoName = 'MotCtrlMgr';
MotVltgDax.EngDT = dt.float32;
MotVltgDax.EngInit = 0;
MotVltgDax.EngMin = -26.5;
MotVltgDax.EngMax = 26.5;
MotVltgDax.TestTolerance = 0;
MotVltgDax.WrittenIn = {'MotCtrlMgrPer1'};
MotVltgDax.WriteType = 'Rte';


MotVltgQax = DataDict.OpSignal;
MotVltgQax.LongName = 'MotVltgQax';
MotVltgQax.Description = 'MotVltgQax';
MotVltgQax.DocUnits = 'Volt';
MotVltgQax.SwcShoName = 'MotCtrlMgr';
MotVltgQax.EngDT = dt.float32;
MotVltgQax.EngInit = 0;
MotVltgQax.EngMin = -26.5;
MotVltgQax.EngMax = 26.5;
MotVltgQax.TestTolerance = 0;
MotVltgQax.WrittenIn = {'MotCtrlMgrPer1'};
MotVltgQax.WriteType = 'Rte';


Ntc5DErrCnt = DataDict.OpSignal;
Ntc5DErrCnt.LongName = 'Ntc5DErrCnt';
Ntc5DErrCnt.Description = 'Ntc5DErrCnt';
Ntc5DErrCnt.DocUnits = 'Cnt';
Ntc5DErrCnt.SwcShoName = 'MotCtrlMgr';
Ntc5DErrCnt.EngDT = dt.u16;
Ntc5DErrCnt.EngInit = 0;
Ntc5DErrCnt.EngMin = 0;
Ntc5DErrCnt.EngMax = 65535;
Ntc5DErrCnt.TestTolerance = 0;
Ntc5DErrCnt.WrittenIn = {'MotCtrlMgrPer1'};
Ntc5DErrCnt.WriteType = 'Rte';


PhaOnTiSumA = DataDict.OpSignal;
PhaOnTiSumA.LongName = 'PhaOnTiSumA';
PhaOnTiSumA.Description = 'PhaOnTiSumA';
PhaOnTiSumA.DocUnits = 'NanoSec';
PhaOnTiSumA.SwcShoName = 'MotCtrlMgr';
PhaOnTiSumA.EngDT = dt.u32;
PhaOnTiSumA.EngInit = 0;
PhaOnTiSumA.EngMin = 0;
PhaOnTiSumA.EngMax = 4294967295;
PhaOnTiSumA.TestTolerance = 0;
PhaOnTiSumA.WrittenIn = {'MotCtrlMgrPer1'};
PhaOnTiSumA.WriteType = 'Rte';


PhaOnTiSumB = DataDict.OpSignal;
PhaOnTiSumB.LongName = 'PhaOnTiSumB';
PhaOnTiSumB.Description = 'PhaOnTiSumB';
PhaOnTiSumB.DocUnits = 'NanoSec';
PhaOnTiSumB.SwcShoName = 'MotCtrlMgr';
PhaOnTiSumB.EngDT = dt.u32;
PhaOnTiSumB.EngInit = 0;
PhaOnTiSumB.EngMin = 0;
PhaOnTiSumB.EngMax = 4294967295;
PhaOnTiSumB.TestTolerance = 0;
PhaOnTiSumB.WrittenIn = {'MotCtrlMgrPer1'};
PhaOnTiSumB.WriteType = 'Rte';


PhaOnTiSumC = DataDict.OpSignal;
PhaOnTiSumC.LongName = 'PhaOnTiSumC';
PhaOnTiSumC.Description = 'PhaOnTiSumC';
PhaOnTiSumC.DocUnits = 'NanoSec';
PhaOnTiSumC.SwcShoName = 'MotCtrlMgr';
PhaOnTiSumC.EngDT = dt.u32;
PhaOnTiSumC.EngInit = 0;
PhaOnTiSumC.EngMin = 0;
PhaOnTiSumC.EngMax = 4294967295;
PhaOnTiSumC.TestTolerance = 0;
PhaOnTiSumC.WrittenIn = {'MotCtrlMgrPer1'};
PhaOnTiSumC.WriteType = 'Rte';


SlowLoopCntr = DataDict.OpSignal;
SlowLoopCntr.LongName = 'SlowLoopCntr';
SlowLoopCntr.Description = 'SlowLoopCntr';
SlowLoopCntr.DocUnits = 'Cnt';
SlowLoopCntr.SwcShoName = 'MotCtrlMgr';
SlowLoopCntr.EngDT = dt.u16;
SlowLoopCntr.EngInit = 0;
SlowLoopCntr.EngMin = 0;
SlowLoopCntr.EngMax = 65535;
SlowLoopCntr.TestTolerance = 0;
SlowLoopCntr.WrittenIn = {'MotCtrlMgrPer1'};
SlowLoopCntr.WriteType = 'Rte';



%%-------------------------------------------
%% Inter-Runnable Variable Definition        
%%-------------------------------------------

%%-------------------------------------------
%% Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Imported Calibrations Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Non-Volatile Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Display Variable Definition               
%%-------------------------------------------

%%-------------------------------------------
%% Per-Instance Memory Definition            
%%-------------------------------------------

%%-------------------------------------------
%% Constant Definition                       
%%-------------------------------------------

%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
