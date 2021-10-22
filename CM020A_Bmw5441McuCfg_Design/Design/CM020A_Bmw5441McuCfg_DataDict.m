%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 24-May-2018 17:02:45       %
%                                  Created with tool release: 3.3.0      %
%                                  Synergy file: %version: 16 %           %
%                                  Derived by: %derived_by: tzbsjd %          %
%%-----------------------------------------------------------------------%

CM020A = DataDict.FDD;
CM020A.Version = '1.15.X';
CM020A.LongName = 'BMW 5441 Microcontroller Unit Configuration';
CM020A.ShoName  = 'Bmw5441McuCfg';
CM020A.DesignASIL = 'D';
CM020A.Description = [...
  'Program specific I/O and Constant settings for the BMW 5441 Program'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
Bmw5441McuCfgInit1 = DataDict.Runnable;
Bmw5441McuCfgInit1.Context = 'Rte';
Bmw5441McuCfgInit1.TimeStep = 0;
Bmw5441McuCfgInit1.Description = [...
  'This function initializes the applicable registers'];

Bmw5441McuCfgInit2 = DataDict.Runnable;
Bmw5441McuCfgInit2.Context = 'Rte';
Bmw5441McuCfgInit2.TimeStep = 0;
Bmw5441McuCfgInit2.Description = [...
  'Performs the Raw ADC to Volts conversion on Adc0'];

Bmw5441McuCfgInit3 = DataDict.Runnable;
Bmw5441McuCfgInit3.Context = 'Rte';
Bmw5441McuCfgInit3.TimeStep = 0;
Bmw5441McuCfgInit3.Description = [...
  'Performs the Raw ADC to Volts conversion on Adc1'];

Bmw5441McuCfgPer1 = DataDict.Runnable;
Bmw5441McuCfgPer1.Context = 'NonRte';
Bmw5441McuCfgPer1.TimeStep = 'MotorControl';
Bmw5441McuCfgPer1.Description = [...
  'Performs the Raw ADC to Volts conversion on Adc0'];

Bmw5441McuCfgPer2 = DataDict.Runnable;
Bmw5441McuCfgPer2.Context = 'Rte';
Bmw5441McuCfgPer2.TimeStep = 0.002;
Bmw5441McuCfgPer2.Description = [...
  'Performs the Raw ADC to Volts conversion on Adc1'];

Bmw5441McuCfgPer3 = DataDict.Runnable;
Bmw5441McuCfgPer3.Context = 'Rte';
Bmw5441McuCfgPer3.TimeStep = 0.002;
Bmw5441McuCfgPer3.Description = [...
  'Performs the Adc dynamic diagnostic'];


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
GetRefTmr1MicroSec32bit = DataDict.Client;
GetRefTmr1MicroSec32bit.CallLocation = {'Bmw5441McuCfgInit2'};
GetRefTmr1MicroSec32bit.Description = [...
  'Generic timer function to get reference timer tick in 1 uSec resolutio' ...
  'n'];
GetRefTmr1MicroSec32bit.Return = DataDict.CSReturn;
GetRefTmr1MicroSec32bit.Return.Type = 'None';
GetRefTmr1MicroSec32bit.Return.Min = [];
GetRefTmr1MicroSec32bit.Return.Max = [];
GetRefTmr1MicroSec32bit.Return.TestTolerance = [];
GetRefTmr1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetRefTmr1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetRefTmr1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetRefTmr1MicroSec32bit.Arguments(1).EngMin = 0;
GetRefTmr1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetRefTmr1MicroSec32bit.Arguments(1).TestTolerance = 0;
GetRefTmr1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetRefTmr1MicroSec32bit.Arguments(1).Direction = 'Out';
GetRefTmr1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetRefTmr1MicroSec32bit.Arguments(1).Description = [...
  'Reference time tick in 1 uSec resolution'];


GetTiSpan1MicroSec32bit = DataDict.Client;
GetTiSpan1MicroSec32bit.CallLocation = {'Bmw5441McuCfgInit2'};
GetTiSpan1MicroSec32bit.Description = [...
  'Generic timer function to get time span between input reference time a' ...
  'nd current time'];
GetTiSpan1MicroSec32bit.Return = DataDict.CSReturn;
GetTiSpan1MicroSec32bit.Return.Type = 'None';
GetTiSpan1MicroSec32bit.Return.Min = [];
GetTiSpan1MicroSec32bit.Return.Max = [];
GetTiSpan1MicroSec32bit.Return.TestTolerance = [];
GetTiSpan1MicroSec32bit.Arguments(1) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(1).Name = 'RefTmr';
GetTiSpan1MicroSec32bit.Arguments(1).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(1).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(1).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(1).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(1).Direction = 'In';
GetTiSpan1MicroSec32bit.Arguments(1).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(1).Description = [...
  'Reference time tick in 1 uSec resolution'];
GetTiSpan1MicroSec32bit.Arguments(2) = DataDict.CSArguments;
GetTiSpan1MicroSec32bit.Arguments(2).Name = 'TiSpan';
GetTiSpan1MicroSec32bit.Arguments(2).EngDT = dt.u32;
GetTiSpan1MicroSec32bit.Arguments(2).EngMin = 0;
GetTiSpan1MicroSec32bit.Arguments(2).EngMax = 4294967295;
GetTiSpan1MicroSec32bit.Arguments(2).TestTolerance = 0;
GetTiSpan1MicroSec32bit.Arguments(2).Units = 'Cnt';
GetTiSpan1MicroSec32bit.Arguments(2).Direction = 'Out';
GetTiSpan1MicroSec32bit.Arguments(2).InitRowCol = [1  1];
GetTiSpan1MicroSec32bit.Arguments(2).Description = [...
  'Time span between input reference time and current time'];



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------
Adc0Faild = DataDict.IpSignal;
Adc0Faild.LongName = 'ADC 0 Failed';
Adc0Faild.Description = [...
  'Indication that Adc0 has failed its diagnostic'];
Adc0Faild.DocUnits = 'Cnt';
Adc0Faild.EngDT = dt.lgc;
Adc0Faild.EngInit = 0;
Adc0Faild.EngMin = 0;
Adc0Faild.EngMax = 1;
Adc0Faild.ReadIn = {'Bmw5441McuCfgPer3'};
Adc0Faild.ReadType = 'Rte';


Adc1Faild = DataDict.IpSignal;
Adc1Faild.LongName = 'ADC 1 Failed';
Adc1Faild.Description = [...
  'Indication that Adc1 has failed its diagnostic'];
Adc1Faild.DocUnits = 'Cnt';
Adc1Faild.EngDT = dt.lgc;
Adc1Faild.EngInit = 0;
Adc1Faild.EngMin = 0;
Adc1Faild.EngMax = 1;
Adc1Faild.ReadIn = {'Bmw5441McuCfgPer3'};
Adc1Faild.ReadType = 'Rte';


Adc1RawRes = DataDict.IpSignal;
Adc1RawRes.LongName = 'Adc1 Raw Results';
Adc1RawRes.Description = 'Local RAM copy of all Adc1 results';
Adc1RawRes.DocUnits = 'Cnt';
Adc1RawRes.EngDT = dt.u16;
Adc1RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
Adc1RawRes.EngMin = 0;
Adc1RawRes.EngMax = 4095;
Adc1RawRes.ReadIn = {'Bmw5441McuCfgPer2'};
Adc1RawRes.ReadType = 'Rte';


MotCtrlAdc0RawRes = DataDict.IpSignal;
MotCtrlAdc0RawRes.LongName = 'Adc0 Raw Results';
MotCtrlAdc0RawRes.Description = 'Local RAM copy of all Adc0 results';
MotCtrlAdc0RawRes.DocUnits = 'Cnt';
MotCtrlAdc0RawRes.EngDT = dt.u16;
MotCtrlAdc0RawRes.EngInit =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
MotCtrlAdc0RawRes.EngMin = 0;
MotCtrlAdc0RawRes.EngMax = 4095;
MotCtrlAdc0RawRes.ReadIn = {'Bmw5441McuCfgPer1'};
MotCtrlAdc0RawRes.ReadType = 'NonRte';



%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------
Adc1ScanGroup2Ref0 = DataDict.OpSignal;
Adc1ScanGroup2Ref0.LongName = 'Adc1 Scan Group 2 Ref 0';
Adc1ScanGroup2Ref0.Description = [...
  'Adc1ScanGroup2 internal reference results read at start of scan group ' ...
  'read'];
Adc1ScanGroup2Ref0.DocUnits = 'Volt';
Adc1ScanGroup2Ref0.SwcShoName = 'Bmw5441McuCfg';
Adc1ScanGroup2Ref0.EngDT = dt.float32;
Adc1ScanGroup2Ref0.EngInit = 0;
Adc1ScanGroup2Ref0.EngMin = 0;
Adc1ScanGroup2Ref0.EngMax = 5;
Adc1ScanGroup2Ref0.TestTolerance = 0.001221001221;
Adc1ScanGroup2Ref0.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1ScanGroup2Ref0.WriteType = 'Rte';


Adc1ScanGroup2Ref1 = DataDict.OpSignal;
Adc1ScanGroup2Ref1.LongName = 'Adc1 Scan Group 2 Ref 1';
Adc1ScanGroup2Ref1.Description = [...
  'Adc1ScanGroup2 internal reference results read at end of scan group re' ...
  'ad'];
Adc1ScanGroup2Ref1.DocUnits = 'Volt';
Adc1ScanGroup2Ref1.SwcShoName = 'Bmw5441McuCfg';
Adc1ScanGroup2Ref1.EngDT = dt.float32;
Adc1ScanGroup2Ref1.EngInit = 0;
Adc1ScanGroup2Ref1.EngMin = 0;
Adc1ScanGroup2Ref1.EngMax = 5;
Adc1ScanGroup2Ref1.TestTolerance = 0.001221001221;
Adc1ScanGroup2Ref1.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1ScanGroup2Ref1.WriteType = 'Rte';


Adc1ScanGroup3Ref0 = DataDict.OpSignal;
Adc1ScanGroup3Ref0.LongName = 'Adc1 Scan Group 3 Ref 0';
Adc1ScanGroup3Ref0.Description = [...
  'Adc1ScanGroup3 internal reference results read at start of scan group ' ...
  'read'];
Adc1ScanGroup3Ref0.DocUnits = 'Volt';
Adc1ScanGroup3Ref0.SwcShoName = 'Bmw5441McuCfg';
Adc1ScanGroup3Ref0.EngDT = dt.float32;
Adc1ScanGroup3Ref0.EngInit = 0;
Adc1ScanGroup3Ref0.EngMin = 0;
Adc1ScanGroup3Ref0.EngMax = 5;
Adc1ScanGroup3Ref0.TestTolerance = 0.001221001221;
Adc1ScanGroup3Ref0.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1ScanGroup3Ref0.WriteType = 'Rte';


Adc1ScanGroup3Ref1 = DataDict.OpSignal;
Adc1ScanGroup3Ref1.LongName = 'Adc1 Scan Group 3 Ref 1';
Adc1ScanGroup3Ref1.Description = [...
  'Adc1ScanGroup3 internal reference results read at end of scan group re' ...
  'ad'];
Adc1ScanGroup3Ref1.DocUnits = 'Volt';
Adc1ScanGroup3Ref1.SwcShoName = 'Bmw5441McuCfg';
Adc1ScanGroup3Ref1.EngDT = dt.float32;
Adc1ScanGroup3Ref1.EngInit = 0;
Adc1ScanGroup3Ref1.EngMin = 0;
Adc1ScanGroup3Ref1.EngMax = 5;
Adc1ScanGroup3Ref1.TestTolerance = 0.001221001221;
Adc1ScanGroup3Ref1.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1ScanGroup3Ref1.WriteType = 'Rte';


Adc1SelfDiag0 = DataDict.OpSignal;
Adc1SelfDiag0.LongName = 'Adc1 Self Diagnosis 0';
Adc1SelfDiag0.Description = [...
  'First of 3 dynamic Adc1 reads used for diagnostic purposes'];
Adc1SelfDiag0.DocUnits = 'Volt';
Adc1SelfDiag0.SwcShoName = 'Bmw5441McuCfg';
Adc1SelfDiag0.EngDT = dt.float32;
Adc1SelfDiag0.EngInit = 0;
Adc1SelfDiag0.EngMin = 0;
Adc1SelfDiag0.EngMax = 5;
Adc1SelfDiag0.TestTolerance = 0.001221001221;
Adc1SelfDiag0.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1SelfDiag0.WriteType = 'Rte';


Adc1SelfDiag2 = DataDict.OpSignal;
Adc1SelfDiag2.LongName = 'Adc1 Self Diagnosis 2';
Adc1SelfDiag2.Description = [...
  'Second of 3 dynamic Adc1 reads used for diagnostic purposes'];
Adc1SelfDiag2.DocUnits = 'Volt';
Adc1SelfDiag2.SwcShoName = 'Bmw5441McuCfg';
Adc1SelfDiag2.EngDT = dt.float32;
Adc1SelfDiag2.EngInit = 0;
Adc1SelfDiag2.EngMin = 0;
Adc1SelfDiag2.EngMax = 5;
Adc1SelfDiag2.TestTolerance = 0.001221001221;
Adc1SelfDiag2.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1SelfDiag2.WriteType = 'Rte';


Adc1SelfDiag4 = DataDict.OpSignal;
Adc1SelfDiag4.LongName = 'Adc1 Self Diagnosis 4';
Adc1SelfDiag4.Description = [...
  'Third of 3 dynamic Adc1 reads used for diagnostic purposes'];
Adc1SelfDiag4.DocUnits = 'Volt';
Adc1SelfDiag4.SwcShoName = 'Bmw5441McuCfg';
Adc1SelfDiag4.EngDT = dt.float32;
Adc1SelfDiag4.EngInit = 0;
Adc1SelfDiag4.EngMin = 0;
Adc1SelfDiag4.EngMax = 5;
Adc1SelfDiag4.TestTolerance = 0.001221001221;
Adc1SelfDiag4.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
Adc1SelfDiag4.WriteType = 'Rte';


BattRtnCurrAdcFaild = DataDict.OpSignal;
BattRtnCurrAdcFaild.LongName = 'Battery Return Current Adc Failed';
BattRtnCurrAdcFaild.Description = [...
  'The Adc that converts BattRtnCurrAdc has failed'];
BattRtnCurrAdcFaild.DocUnits = 'Cnt';
BattRtnCurrAdcFaild.SwcShoName = 'Bmw5441McuCfg';
BattRtnCurrAdcFaild.EngDT = dt.lgc;
BattRtnCurrAdcFaild.EngInit = 0;
BattRtnCurrAdcFaild.EngMin = 0;
BattRtnCurrAdcFaild.EngMax = 1;
BattRtnCurrAdcFaild.TestTolerance = 0;
BattRtnCurrAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
BattRtnCurrAdcFaild.WriteType = 'Rte';


BattVltgAdcFaild = DataDict.OpSignal;
BattVltgAdcFaild.LongName = 'Battery Voltage  ADC Failed';
BattVltgAdcFaild.Description = [...
  'The Adc that converts MotCtrlBattVltgAdc has failed'];
BattVltgAdcFaild.DocUnits = 'Cnt';
BattVltgAdcFaild.SwcShoName = 'Bmw5441McuCfg';
BattVltgAdcFaild.EngDT = dt.lgc;
BattVltgAdcFaild.EngInit = 0;
BattVltgAdcFaild.EngMin = 0;
BattVltgAdcFaild.EngMax = 1;
BattVltgAdcFaild.TestTolerance = 0;
BattVltgAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
BattVltgAdcFaild.WriteType = 'Rte';


BattVltgSwd1 = DataDict.OpSignal;
BattVltgSwd1.LongName = 'Switched Battery Voltage 1';
BattVltgSwd1.Description = 'Switched Battery Voltage 1';
BattVltgSwd1.DocUnits = 'Volt';
BattVltgSwd1.SwcShoName = 'Bmw5441McuCfg';
BattVltgSwd1.EngDT = dt.float32;
BattVltgSwd1.EngInit = 0;
BattVltgSwd1.EngMin = 0;
BattVltgSwd1.EngMax = 40;
BattVltgSwd1.TestTolerance = 0.001221001221;
BattVltgSwd1.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
BattVltgSwd1.WriteType = 'Rte';


BattVltgSwd1AdcFaild = DataDict.OpSignal;
BattVltgSwd1AdcFaild.LongName = 'Battery Voltage  Switched 1 ADC Failed';
BattVltgSwd1AdcFaild.Description = [...
  'The Adc that converts BattVltgSwd1 has failed'];
BattVltgSwd1AdcFaild.DocUnits = 'Cnt';
BattVltgSwd1AdcFaild.SwcShoName = 'Bmw5441McuCfg';
BattVltgSwd1AdcFaild.EngDT = dt.lgc;
BattVltgSwd1AdcFaild.EngInit = 0;
BattVltgSwd1AdcFaild.EngMin = 0;
BattVltgSwd1AdcFaild.EngMax = 1;
BattVltgSwd1AdcFaild.TestTolerance = 0;
BattVltgSwd1AdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
BattVltgSwd1AdcFaild.WriteType = 'Rte';


EcuT = DataDict.OpSignal;
EcuT.LongName = 'Ecu Temperature';
EcuT.Description = [...
  'Voltage representation of Ecu Temperature, convertered to degC in a di' ...
  'fferent module'];
EcuT.DocUnits = 'Volt';
EcuT.SwcShoName = 'Bmw5441McuCfg';
EcuT.EngDT = dt.float32;
EcuT.EngInit = 0;
EcuT.EngMin = 0;
EcuT.EngMax = 5;
EcuT.TestTolerance = 0.001221001221;
EcuT.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
EcuT.WriteType = 'Rte';


EcuTAdcFaild = DataDict.OpSignal;
EcuTAdcFaild.LongName = 'ECU Temperature ADC Failed';
EcuTAdcFaild.Description = [...
  'The Adc that converts EcuT has failed'];
EcuTAdcFaild.DocUnits = 'Cnt';
EcuTAdcFaild.SwcShoName = 'Bmw5441McuCfg';
EcuTAdcFaild.EngDT = dt.lgc;
EcuTAdcFaild.EngInit = 0;
EcuTAdcFaild.EngMin = 0;
EcuTAdcFaild.EngMax = 1;
EcuTAdcFaild.TestTolerance = 0;
EcuTAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
EcuTAdcFaild.WriteType = 'Rte';


HwTq4RawAdcFaild = DataDict.OpSignal;
HwTq4RawAdcFaild.LongName = 'Motor Control Handwheel Torque 4 Raw ADC Failed';
HwTq4RawAdcFaild.Description = [...
  'Motor Control Handwheel Torque 4 Raw ADC Failed'];
HwTq4RawAdcFaild.DocUnits = 'Cnt';
HwTq4RawAdcFaild.SwcShoName = 'Bmw5441McuCfg';
HwTq4RawAdcFaild.EngDT = dt.lgc;
HwTq4RawAdcFaild.EngInit = 0;
HwTq4RawAdcFaild.EngMin = 0;
HwTq4RawAdcFaild.EngMax = 1;
HwTq4RawAdcFaild.TestTolerance = 0;
HwTq4RawAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
HwTq4RawAdcFaild.WriteType = 'Rte';


HwTq5RawAdcFaild = DataDict.OpSignal;
HwTq5RawAdcFaild.LongName = 'Motor Control Handwheel Torque 5 Raw ADC Failed';
HwTq5RawAdcFaild.Description = [...
  'Motor Control Handwheel Torque 5 Raw ADC Failed'];
HwTq5RawAdcFaild.DocUnits = 'Cnt';
HwTq5RawAdcFaild.SwcShoName = 'Bmw5441McuCfg';
HwTq5RawAdcFaild.EngDT = dt.lgc;
HwTq5RawAdcFaild.EngInit = 0;
HwTq5RawAdcFaild.EngMin = 0;
HwTq5RawAdcFaild.EngMax = 1;
HwTq5RawAdcFaild.TestTolerance = 0;
HwTq5RawAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
HwTq5RawAdcFaild.WriteType = 'Rte';


MotCtrlAdc0ScanGroup2Ref0 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup2Ref0.LongName = 'MotCtrlAdc0ScanGroup2Ref0';
MotCtrlAdc0ScanGroup2Ref0.Description = [...
  'MotCtrlAdc0ScanGroup2Ref0 - reference read perfomed at start of scan g' ...
  'roup read'];
MotCtrlAdc0ScanGroup2Ref0.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup2Ref0.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0ScanGroup2Ref0.EngDT = dt.float32;
MotCtrlAdc0ScanGroup2Ref0.EngInit = 0;
MotCtrlAdc0ScanGroup2Ref0.EngMin = 0;
MotCtrlAdc0ScanGroup2Ref0.EngMax = 5;
MotCtrlAdc0ScanGroup2Ref0.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup2Ref0.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0ScanGroup2Ref0.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup2Ref1 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup2Ref1.LongName = 'MotCtrlAdc0ScanGroup2Ref1';
MotCtrlAdc0ScanGroup2Ref1.Description = [...
  'MotCtrlAdc0ScanGroup2Ref1 - reference read perfomed at end of scan gro' ...
  'up read'];
MotCtrlAdc0ScanGroup2Ref1.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup2Ref1.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0ScanGroup2Ref1.EngDT = dt.float32;
MotCtrlAdc0ScanGroup2Ref1.EngInit = 0;
MotCtrlAdc0ScanGroup2Ref1.EngMin = 0;
MotCtrlAdc0ScanGroup2Ref1.EngMax = 5;
MotCtrlAdc0ScanGroup2Ref1.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup2Ref1.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0ScanGroup2Ref1.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup3Ref0 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup3Ref0.LongName = 'MotCtrlAdc0ScanGroup3Ref0';
MotCtrlAdc0ScanGroup3Ref0.Description = [...
  'MotCtrlAdc0ScanGroup3Ref0 - reference read perfomed at start of scan g' ...
  'roup read'];
MotCtrlAdc0ScanGroup3Ref0.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup3Ref0.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0ScanGroup3Ref0.EngDT = dt.float32;
MotCtrlAdc0ScanGroup3Ref0.EngInit = 0;
MotCtrlAdc0ScanGroup3Ref0.EngMin = 0;
MotCtrlAdc0ScanGroup3Ref0.EngMax = 5;
MotCtrlAdc0ScanGroup3Ref0.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup3Ref0.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0ScanGroup3Ref0.WriteType = 'NonRte';


MotCtrlAdc0ScanGroup3Ref1 = DataDict.OpSignal;
MotCtrlAdc0ScanGroup3Ref1.LongName = 'MotCtrlAdc0ScanGroup3Ref1';
MotCtrlAdc0ScanGroup3Ref1.Description = [...
  'MotCtrlAdc0ScanGroup3Ref1 - reference read perfomed at end of scan gro' ...
  'up read'];
MotCtrlAdc0ScanGroup3Ref1.DocUnits = 'Volt';
MotCtrlAdc0ScanGroup3Ref1.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0ScanGroup3Ref1.EngDT = dt.float32;
MotCtrlAdc0ScanGroup3Ref1.EngInit = 0;
MotCtrlAdc0ScanGroup3Ref1.EngMin = 0;
MotCtrlAdc0ScanGroup3Ref1.EngMax = 5;
MotCtrlAdc0ScanGroup3Ref1.TestTolerance = 0.001221001221;
MotCtrlAdc0ScanGroup3Ref1.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0ScanGroup3Ref1.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag0 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag0.LongName = 'Adc0 Self Diagnostic 0';
MotCtrlAdc0SelfDiag0.Description = [...
  'First of 3 dynamic Adc1 reads used for diagnostic purposes'];
MotCtrlAdc0SelfDiag0.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag0.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0SelfDiag0.EngDT = dt.float32;
MotCtrlAdc0SelfDiag0.EngInit = 0;
MotCtrlAdc0SelfDiag0.EngMin = 0;
MotCtrlAdc0SelfDiag0.EngMax = 5;
MotCtrlAdc0SelfDiag0.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag0.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0SelfDiag0.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag2 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag2.LongName = 'Adc0 Self Diagnostic 2';
MotCtrlAdc0SelfDiag2.Description = [...
  'Second of 3 dynamic Adc1 reads used for diagnostic purposes'];
MotCtrlAdc0SelfDiag2.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag2.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0SelfDiag2.EngDT = dt.float32;
MotCtrlAdc0SelfDiag2.EngInit = 0;
MotCtrlAdc0SelfDiag2.EngMin = 0;
MotCtrlAdc0SelfDiag2.EngMax = 5;
MotCtrlAdc0SelfDiag2.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag2.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0SelfDiag2.WriteType = 'NonRte';


MotCtrlAdc0SelfDiag4 = DataDict.OpSignal;
MotCtrlAdc0SelfDiag4.LongName = 'Adc0 Self Diagnostic 4';
MotCtrlAdc0SelfDiag4.Description = [...
  'Third of 3 dynamic Adc1 reads used for diagnostic purposes'];
MotCtrlAdc0SelfDiag4.DocUnits = 'Volt';
MotCtrlAdc0SelfDiag4.SwcShoName = 'Bmw5441McuCfg';
MotCtrlAdc0SelfDiag4.EngDT = dt.float32;
MotCtrlAdc0SelfDiag4.EngInit = 0;
MotCtrlAdc0SelfDiag4.EngMin = 0;
MotCtrlAdc0SelfDiag4.EngMax = 5;
MotCtrlAdc0SelfDiag4.TestTolerance = 0.001221001221;
MotCtrlAdc0SelfDiag4.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlAdc0SelfDiag4.WriteType = 'NonRte';


MotCtrlBattRtnCurrAdc = DataDict.OpSignal;
MotCtrlBattRtnCurrAdc.LongName = 'Battery Return Current Adc';
MotCtrlBattRtnCurrAdc.Description = [...
  'Battery Return Current Adc measurement'];
MotCtrlBattRtnCurrAdc.DocUnits = 'Volt';
MotCtrlBattRtnCurrAdc.SwcShoName = 'Bmw5441McuCfg';
MotCtrlBattRtnCurrAdc.EngDT = dt.float32;
MotCtrlBattRtnCurrAdc.EngInit = 0;
MotCtrlBattRtnCurrAdc.EngMin = 0;
MotCtrlBattRtnCurrAdc.EngMax = 5;
MotCtrlBattRtnCurrAdc.TestTolerance = 0.001221001221;
MotCtrlBattRtnCurrAdc.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlBattRtnCurrAdc.WriteType = 'NonRte';


MotCtrlBattVltgAdc = DataDict.OpSignal;
MotCtrlBattVltgAdc.LongName = 'Battery Voltage ADC';
MotCtrlBattVltgAdc.Description = [...
  'Filtered Battery Voltage ADC measurement'];
MotCtrlBattVltgAdc.DocUnits = 'Volt';
MotCtrlBattVltgAdc.SwcShoName = 'Bmw5441McuCfg';
MotCtrlBattVltgAdc.EngDT = dt.float32;
MotCtrlBattVltgAdc.EngInit = 0;
MotCtrlBattVltgAdc.EngMin = 0;
MotCtrlBattVltgAdc.EngMax = 40;
MotCtrlBattVltgAdc.TestTolerance = 0.001221001221;
MotCtrlBattVltgAdc.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlBattVltgAdc.WriteType = 'NonRte';


MotCtrlHwTq4RawAdc = DataDict.OpSignal;
MotCtrlHwTq4RawAdc.LongName = 'Handwheel Torque 4 Raw ADC';
MotCtrlHwTq4RawAdc.Description = [...
  'HwTrq4 signal as converted by the Adc'];
MotCtrlHwTq4RawAdc.DocUnits = 'Volt';
MotCtrlHwTq4RawAdc.SwcShoName = 'Bmw5441McuCfg';
MotCtrlHwTq4RawAdc.EngDT = dt.float32;
MotCtrlHwTq4RawAdc.EngInit = 0;
MotCtrlHwTq4RawAdc.EngMin = 0;
MotCtrlHwTq4RawAdc.EngMax = 5;
MotCtrlHwTq4RawAdc.TestTolerance = 0.001221001221;
MotCtrlHwTq4RawAdc.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlHwTq4RawAdc.WriteType = 'NonRte';


MotCtrlHwTq5RawAdc = DataDict.OpSignal;
MotCtrlHwTq5RawAdc.LongName = 'Motor Control Handwheel Torque 5 Raw ADC';
MotCtrlHwTq5RawAdc.Description = [...
  'Motor Control HwTrq5 signal as converted by the Adc'];
MotCtrlHwTq5RawAdc.DocUnits = 'Volt';
MotCtrlHwTq5RawAdc.SwcShoName = 'Bmw5441McuCfg';
MotCtrlHwTq5RawAdc.EngDT = dt.float32;
MotCtrlHwTq5RawAdc.EngInit = 0;
MotCtrlHwTq5RawAdc.EngMin = 0;
MotCtrlHwTq5RawAdc.EngMax = 5;
MotCtrlHwTq5RawAdc.TestTolerance = 0.001221001221;
MotCtrlHwTq5RawAdc.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlHwTq5RawAdc.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakA = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakA.LongName = 'Motor Current A Sampled at Peak';
MotCtrlMotCurrAdcPeakA.Description = 'Motor Current A Sampled at Peak';
MotCtrlMotCurrAdcPeakA.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakA.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcPeakA.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakA.EngInit = 0;
MotCtrlMotCurrAdcPeakA.EngMin = 0;
MotCtrlMotCurrAdcPeakA.EngMax = 5;
MotCtrlMotCurrAdcPeakA.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakA.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcPeakA.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakB = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakB.LongName = 'Motor Current B Sampled at Peak';
MotCtrlMotCurrAdcPeakB.Description = 'Motor Current B Sampled at Peak';
MotCtrlMotCurrAdcPeakB.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakB.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcPeakB.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakB.EngInit = 0;
MotCtrlMotCurrAdcPeakB.EngMin = 0;
MotCtrlMotCurrAdcPeakB.EngMax = 5;
MotCtrlMotCurrAdcPeakB.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakB.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcPeakB.WriteType = 'NonRte';


MotCtrlMotCurrAdcPeakC = DataDict.OpSignal;
MotCtrlMotCurrAdcPeakC.LongName = 'Motor Current C Sampled at Peak';
MotCtrlMotCurrAdcPeakC.Description = 'Motor Current C Sampled at Peak';
MotCtrlMotCurrAdcPeakC.DocUnits = 'Volt';
MotCtrlMotCurrAdcPeakC.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcPeakC.EngDT = dt.float32;
MotCtrlMotCurrAdcPeakC.EngInit = 0;
MotCtrlMotCurrAdcPeakC.EngMin = 0;
MotCtrlMotCurrAdcPeakC.EngMax = 5;
MotCtrlMotCurrAdcPeakC.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcPeakC.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcPeakC.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyA = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyA.LongName = 'Motor Current A Sampled at Valley';
MotCtrlMotCurrAdcVlyA.Description = 'Motor Current A Sampled at Valley';
MotCtrlMotCurrAdcVlyA.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyA.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcVlyA.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyA.EngInit = 0;
MotCtrlMotCurrAdcVlyA.EngMin = 0;
MotCtrlMotCurrAdcVlyA.EngMax = 5;
MotCtrlMotCurrAdcVlyA.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyA.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcVlyA.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyB = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyB.LongName = 'Motor Current B Sampled at Valley';
MotCtrlMotCurrAdcVlyB.Description = 'Motor Current B Sampled at Valley';
MotCtrlMotCurrAdcVlyB.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyB.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcVlyB.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyB.EngInit = 0;
MotCtrlMotCurrAdcVlyB.EngMin = 0;
MotCtrlMotCurrAdcVlyB.EngMax = 5;
MotCtrlMotCurrAdcVlyB.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyB.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcVlyB.WriteType = 'NonRte';


MotCtrlMotCurrAdcVlyC = DataDict.OpSignal;
MotCtrlMotCurrAdcVlyC.LongName = 'Motor Current C Sampled at Valley';
MotCtrlMotCurrAdcVlyC.Description = 'Motor Current C Sampled at Valley';
MotCtrlMotCurrAdcVlyC.DocUnits = 'Volt';
MotCtrlMotCurrAdcVlyC.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrAdcVlyC.EngDT = dt.float32;
MotCtrlMotCurrAdcVlyC.EngInit = 0;
MotCtrlMotCurrAdcVlyC.EngMin = 0;
MotCtrlMotCurrAdcVlyC.EngMax = 5;
MotCtrlMotCurrAdcVlyC.TestTolerance = 0.001221001221;
MotCtrlMotCurrAdcVlyC.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrAdcVlyC.WriteType = 'NonRte';


MotCtrlMotCurrSnsrOffs1 = DataDict.OpSignal;
MotCtrlMotCurrSnsrOffs1.LongName = 'Motor Current 1 Offset';
MotCtrlMotCurrSnsrOffs1.Description = 'Motor Current 1 Offset';
MotCtrlMotCurrSnsrOffs1.DocUnits = 'Volt';
MotCtrlMotCurrSnsrOffs1.SwcShoName = 'Bmw5441McuCfg';
MotCtrlMotCurrSnsrOffs1.EngDT = dt.float32;
MotCtrlMotCurrSnsrOffs1.EngInit = 0;
MotCtrlMotCurrSnsrOffs1.EngMin = 0;
MotCtrlMotCurrSnsrOffs1.EngMax = 5;
MotCtrlMotCurrSnsrOffs1.TestTolerance = 0.001221001221;
MotCtrlMotCurrSnsrOffs1.WrittenIn = {'Bmw5441McuCfgInit2','Bmw5441McuCfgPer1'};
MotCtrlMotCurrSnsrOffs1.WriteType = 'NonRte';


MotCurrAdcPeakAAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakAAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak A/Acceleration ADC Failed';
MotCurrAdcPeakAAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakA has failed'];
MotCurrAdcPeakAAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakAAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcPeakAAdcFaild.EngDT = dt.float32;
MotCurrAdcPeakAAdcFaild.EngInit = 0;
MotCurrAdcPeakAAdcFaild.EngMin = 0;
MotCurrAdcPeakAAdcFaild.EngMax = 5;
MotCurrAdcPeakAAdcFaild.TestTolerance = 0;
MotCurrAdcPeakAAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcPeakAAdcFaild.WriteType = 'Rte';


MotCurrAdcPeakBAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakBAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak B ADC Failed';
MotCurrAdcPeakBAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakB has failed'];
MotCurrAdcPeakBAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakBAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcPeakBAdcFaild.EngDT = dt.lgc;
MotCurrAdcPeakBAdcFaild.EngInit = 0;
MotCurrAdcPeakBAdcFaild.EngMin = 0;
MotCurrAdcPeakBAdcFaild.EngMax = 1;
MotCurrAdcPeakBAdcFaild.TestTolerance = 0;
MotCurrAdcPeakBAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcPeakBAdcFaild.WriteType = 'Rte';


MotCurrAdcPeakCAdcFaild = DataDict.OpSignal;
MotCurrAdcPeakCAdcFaild.LongName = 'Motor Control Motor Current/I ADC Peak C ADC Failed';
MotCurrAdcPeakCAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcPeakC has failed'];
MotCurrAdcPeakCAdcFaild.DocUnits = 'Cnt';
MotCurrAdcPeakCAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcPeakCAdcFaild.EngDT = dt.lgc;
MotCurrAdcPeakCAdcFaild.EngInit = 0;
MotCurrAdcPeakCAdcFaild.EngMin = 0;
MotCurrAdcPeakCAdcFaild.EngMax = 1;
MotCurrAdcPeakCAdcFaild.TestTolerance = 0;
MotCurrAdcPeakCAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcPeakCAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyAAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyAAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley A/Acceleration ADC Failed';
MotCurrAdcVlyAAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyA has failed'];
MotCurrAdcVlyAAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyAAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcVlyAAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyAAdcFaild.EngInit = 0;
MotCurrAdcVlyAAdcFaild.EngMin = 0;
MotCurrAdcVlyAAdcFaild.EngMax = 1;
MotCurrAdcVlyAAdcFaild.TestTolerance = 0;
MotCurrAdcVlyAAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcVlyAAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyBAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyBAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley B ADC Failed';
MotCurrAdcVlyBAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyB has failed'];
MotCurrAdcVlyBAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyBAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcVlyBAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyBAdcFaild.EngInit = 0;
MotCurrAdcVlyBAdcFaild.EngMin = 0;
MotCurrAdcVlyBAdcFaild.EngMax = 1;
MotCurrAdcVlyBAdcFaild.TestTolerance = 0;
MotCurrAdcVlyBAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcVlyBAdcFaild.WriteType = 'Rte';


MotCurrAdcVlyCAdcFaild = DataDict.OpSignal;
MotCurrAdcVlyCAdcFaild.LongName = 'Motor Control Motor Current/I ADC Valley C ADC Failed';
MotCurrAdcVlyCAdcFaild.Description = [...
  'The Adc that converts MotCurrAdcVlyC has failed'];
MotCurrAdcVlyCAdcFaild.DocUnits = 'Cnt';
MotCurrAdcVlyCAdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrAdcVlyCAdcFaild.EngDT = dt.lgc;
MotCurrAdcVlyCAdcFaild.EngInit = 0;
MotCurrAdcVlyCAdcFaild.EngMin = 0;
MotCurrAdcVlyCAdcFaild.EngMax = 1;
MotCurrAdcVlyCAdcFaild.TestTolerance = 0;
MotCurrAdcVlyCAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrAdcVlyCAdcFaild.WriteType = 'Rte';


MotCurrSnsrOffs1AdcFaild = DataDict.OpSignal;
MotCurrSnsrOffs1AdcFaild.LongName = 'Motor Control Motor Current/I Sensor Offset 1 ADC Failed';
MotCurrSnsrOffs1AdcFaild.Description = [...
  'The Adc that converts MotCurrSnsrOffs1 has failed'];
MotCurrSnsrOffs1AdcFaild.DocUnits = 'Cnt';
MotCurrSnsrOffs1AdcFaild.SwcShoName = 'Bmw5441McuCfg';
MotCurrSnsrOffs1AdcFaild.EngDT = dt.lgc;
MotCurrSnsrOffs1AdcFaild.EngInit = 0;
MotCurrSnsrOffs1AdcFaild.EngMin = 0;
MotCurrSnsrOffs1AdcFaild.EngMax = 1;
MotCurrSnsrOffs1AdcFaild.TestTolerance = 0;
MotCurrSnsrOffs1AdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
MotCurrSnsrOffs1AdcFaild.WriteType = 'Rte';


MotDrvr1IninTestCmpl = DataDict.OpSignal;
MotDrvr1IninTestCmpl.LongName = 'Motor Driver 1 Initialization Test Complete';
MotDrvr1IninTestCmpl.Description = [...
  'Warm Init configuration and verification test complete flag - dummy si' ...
  'gnal for other FDDs'];
MotDrvr1IninTestCmpl.DocUnits = 'Cnt';
MotDrvr1IninTestCmpl.SwcShoName = 'Bmw5441McuCfg';
MotDrvr1IninTestCmpl.EngDT = dt.lgc;
MotDrvr1IninTestCmpl.EngInit = 0;
MotDrvr1IninTestCmpl.EngMin = 0;
MotDrvr1IninTestCmpl.EngMax = 1;
MotDrvr1IninTestCmpl.TestTolerance = 0;
MotDrvr1IninTestCmpl.WrittenIn = {'Bmw5441McuCfgPer3'};
MotDrvr1IninTestCmpl.WriteType = 'Rte';


RvsBattDiagcGndAdc = DataDict.OpSignal;
RvsBattDiagcGndAdc.LongName = 'Reverse Battery Diagnostics Ground Adc';
RvsBattDiagcGndAdc.Description = [...
  'Reverse Battery Diagnostics Ground Adc measurement'];
RvsBattDiagcGndAdc.DocUnits = 'Volt';
RvsBattDiagcGndAdc.SwcShoName = 'Bmw5441McuCfg';
RvsBattDiagcGndAdc.EngDT = dt.float32;
RvsBattDiagcGndAdc.EngInit = 0;
RvsBattDiagcGndAdc.EngMin = 0;
RvsBattDiagcGndAdc.EngMax = 5;
RvsBattDiagcGndAdc.TestTolerance = 0.001221001221;
RvsBattDiagcGndAdc.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
RvsBattDiagcGndAdc.WriteType = 'Rte';


RvsBattDiagcGndAdcFaild = DataDict.OpSignal;
RvsBattDiagcGndAdcFaild.LongName = 'Reverse Battery Diagnostics Ground Adc Failed';
RvsBattDiagcGndAdcFaild.Description = [...
  'The Adc that converts RvsBattDiagcGndAdc has failed'];
RvsBattDiagcGndAdcFaild.DocUnits = 'Cnt';
RvsBattDiagcGndAdcFaild.SwcShoName = 'Bmw5441McuCfg';
RvsBattDiagcGndAdcFaild.EngDT = dt.lgc;
RvsBattDiagcGndAdcFaild.EngInit = 0;
RvsBattDiagcGndAdcFaild.EngMin = 0;
RvsBattDiagcGndAdcFaild.EngMax = 1;
RvsBattDiagcGndAdcFaild.TestTolerance = 0;
RvsBattDiagcGndAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
RvsBattDiagcGndAdcFaild.WriteType = 'Rte';


RvsBattDiagcRtnAdc = DataDict.OpSignal;
RvsBattDiagcRtnAdc.LongName = 'Reverse Battery Diagnostics Return Adc';
RvsBattDiagcRtnAdc.Description = [...
  'Reverse Battery Diagnostics Return Adc measurement'];
RvsBattDiagcRtnAdc.DocUnits = 'Volt';
RvsBattDiagcRtnAdc.SwcShoName = 'Bmw5441McuCfg';
RvsBattDiagcRtnAdc.EngDT = dt.float32;
RvsBattDiagcRtnAdc.EngInit = 0;
RvsBattDiagcRtnAdc.EngMin = 0;
RvsBattDiagcRtnAdc.EngMax = 5;
RvsBattDiagcRtnAdc.TestTolerance = 0.001221001221;
RvsBattDiagcRtnAdc.WrittenIn = {'Bmw5441McuCfgInit3','Bmw5441McuCfgPer2'};
RvsBattDiagcRtnAdc.WriteType = 'Rte';


RvsBattDiagcRtnAdcFaild = DataDict.OpSignal;
RvsBattDiagcRtnAdcFaild.LongName = 'Reverse Battery Diagnostics Return Adc Failed';
RvsBattDiagcRtnAdcFaild.Description = [...
  'The Adc that converts RvsBattDiagcRtnAdc has failed'];
RvsBattDiagcRtnAdcFaild.DocUnits = 'Cnt';
RvsBattDiagcRtnAdcFaild.SwcShoName = 'Bmw5441McuCfg';
RvsBattDiagcRtnAdcFaild.EngDT = dt.lgc;
RvsBattDiagcRtnAdcFaild.EngInit = 0;
RvsBattDiagcRtnAdcFaild.EngMin = 0;
RvsBattDiagcRtnAdcFaild.EngMax = 1;
RvsBattDiagcRtnAdcFaild.TestTolerance = 0;
RvsBattDiagcRtnAdcFaild.WrittenIn = {'Bmw5441McuCfgPer3'};
RvsBattDiagcRtnAdcFaild.WriteType = 'Rte';



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
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.LongName = 'ADCD0SGVCEP2 Register';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.Description = 'ADC0 Scan Group 2 end pointer';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.EngVal = 14;
ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.LongName = 'ADCD0SGVCEP3 Register';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.Description = 'ADC0 Scan Group 3 end pointer';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.EngVal = 4;
ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.LongName = 'ADCD0SGVCSP2 Register';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.Description = 'ADC0 Scan Group 2 start pointer';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.EngVal = 5;
ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.LongName = 'ADCD0SGVCSP3 Register';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.Description = 'ADC0 Scan Group 3 start pointer';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.EngDT = dt.u08;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.EngVal = 0;
ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR00_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.LongName = 'ADCD0VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.Description = 'Value of the VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.EngVal = 24580;
ADC0CFGANDUSE_ADCD0VCR00_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR01_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.LongName = 'ADCD0VCR01 Register';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.Description = 'Value of the VCR01 Register';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.EngVal = 2;
ADC0CFGANDUSE_ADCD0VCR01_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR02_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.LongName = 'ADCD0VCR02 Register';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.Description = 'Value of the VCR00 Register';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.EngVal = 3;
ADC0CFGANDUSE_ADCD0VCR02_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR03_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.LongName = 'ADCD0VCR03 Register';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.Description = 'Value of the VCR03 Register';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.EngVal = 4;
ADC0CFGANDUSE_ADCD0VCR03_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR04_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.LongName = 'ADCD0VCR04 Register';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.Description = 'Value of the VCR04 Register';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.EngVal = 24588;
ADC0CFGANDUSE_ADCD0VCR04_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR05_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.LongName = 'ADCD0VCR05 Register';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.Description = 'Value of the VCR05 Register';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.EngVal = 24580;
ADC0CFGANDUSE_ADCD0VCR05_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR06_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.LongName = 'ADCD0VCR06 Register';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.Description = 'Value of the VCR06 Register';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.EngVal = 2;
ADC0CFGANDUSE_ADCD0VCR06_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR07_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.LongName = 'ADCD0VCR07 Register';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.Description = 'Value of the VCR07 Register';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.EngVal = 3;
ADC0CFGANDUSE_ADCD0VCR07_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR08_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.LongName = 'ADCD0VCR08 Register';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.Description = 'Value of the VCR08 Register';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.EngVal = 4;
ADC0CFGANDUSE_ADCD0VCR08_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR09_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.LongName = 'ADCD0VCR09 Register';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.Description = 'Value of the VCR09 Register';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.EngVal = 1;
ADC0CFGANDUSE_ADCD0VCR09_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR10_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.LongName = 'ADCD0VCR10 Register';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.Description = 'Value of the VCR10 Register';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.EngVal = 5;
ADC0CFGANDUSE_ADCD0VCR10_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR11_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.LongName = 'ADCD0VCR11 Register';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.Description = 'Value of the VCR11 Register';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.EngVal = 6;
ADC0CFGANDUSE_ADCD0VCR11_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR12_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.LongName = 'ADCD0VCR12 Register';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.Description = 'Value of the VCR12 Register';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.EngVal = 10;
ADC0CFGANDUSE_ADCD0VCR12_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR13_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.LongName = 'ADCD0VCR13 Register';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.Description = 'Value of the VCR13 Register';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.EngVal = 11;
ADC0CFGANDUSE_ADCD0VCR13_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR14_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.LongName = 'ADCD0VCR14 Register';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.Description = 'Value of the VCR14 Register';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.EngVal = 24588;
ADC0CFGANDUSE_ADCD0VCR14_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR15_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.LongName = 'ADCD0VCR15 Register';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.Description = 'Value of the VCR15 Register';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR15_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR16_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.LongName = 'ADCD0VCR16 Register';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.Description = 'Value of the VCR16 Register';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR16_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR17_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.LongName = 'ADCD0VCR17 Register';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.Description = 'Value of the VCR17 Register';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR17_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR18_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.LongName = 'ADCD0VCR18 Register';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.Description = 'Value of the VCR18 Register';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR18_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR19_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.LongName = 'ADCD0VCR19 Register';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.Description = 'Value of the VCR19 Register';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR19_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCD0VCR20_CNT_U32 = DataDict.Constant;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.LongName = 'ADCD0VCR20 Register';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.Description = 'Value of the VCR20 Register';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.DocUnits = 'Cnt';
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.EngDT = dt.u32;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.EngVal = 24584;
ADC0CFGANDUSE_ADCD0VCR20_CNT_U32.Define = 'Local';


ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32 = DataDict.Constant;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.LongName = 'ADC Scaling Factor';
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.Description = [...
  'ADC scaling factor to convert converted counts to volts (5V/4095Cnt)'];
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.DocUnits = 'VoltPerCnt';
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.EngDT = dt.float32;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.EngVal = 0.001221001221;
ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.LongName = 'ADCD1SGVCEP2 Register';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.Description = 'ADC1 Scan Group 2 end pointer';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.EngVal = 7;
ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.LongName = 'ADCD1SGVCEP3 Register';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.Description = 'ADC1 Scan Group 3 end pointer';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.EngVal = 3;
ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.LongName = 'ADCD1SGVCSP2 Register';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.Description = 'ADC1 Scan Group 2 start pointer';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.EngVal = 4;
ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.LongName = 'ADCD1SGVCSP3 Register';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.Description = 'ADC1 Scan Group 3 start pointer';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.EngDT = dt.u08;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.EngVal = 0;
ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR00_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.LongName = 'ADCD1VCR00 Register';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.Description = 'Value of the VCR00 Register';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.EngVal = 24580;
ADC1CFGANDUSE_ADCD1VCR00_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR01_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.LongName = 'ADCD1VCR01 Register';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.Description = 'Value of the VCR01 Register';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.EngVal = 9;
ADC1CFGANDUSE_ADCD1VCR01_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR02_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.LongName = 'ADCD1VCR02 Register';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.Description = 'Value of the VCR02 Register';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.EngVal = 2;
ADC1CFGANDUSE_ADCD1VCR02_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR03_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.LongName = 'ADCD1VCR03 Register';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.Description = 'Value of the VCR03 Register';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.EngVal = 24588;
ADC1CFGANDUSE_ADCD1VCR03_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR04_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.LongName = 'ADCD1VCR04 Register';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.Description = 'Value of the VCR04 Register';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.EngVal = 24580;
ADC1CFGANDUSE_ADCD1VCR04_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR05_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.LongName = 'ADCD1VCR05 Register';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.Description = 'Value of the VCR05 Register';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.EngVal = 4;
ADC1CFGANDUSE_ADCD1VCR05_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR06_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.LongName = 'ADCD1VCR06 Register';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.Description = 'Value of the VCR06 Register';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.EngVal = 6;
ADC1CFGANDUSE_ADCD1VCR06_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR07_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.LongName = 'ADCD1VCR07 Register';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.Description = 'Value of the VCR07 Register';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.EngVal = 24588;
ADC1CFGANDUSE_ADCD1VCR07_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR08_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.LongName = 'ADCD1VCR08 Register';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.Description = 'Value of the VCR08 Register';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR08_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR09_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.LongName = 'ADCD1VCR09 Register';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.Description = 'Value of the VCR09 Register';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR09_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR10_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.LongName = 'ADCD1VCR10 Register';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.Description = 'Value of the VCR10 Register';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR10_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR11_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.LongName = 'ADCD1VCR11 Register';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.Description = 'Value of the VCR11 Register';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR11_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR12_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.LongName = 'ADCD1VCR12 Register';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.Description = 'Value of the VCR12 Register';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR12_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR13_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.LongName = 'ADCD1VCR13 Register';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.Description = 'Value of the VCR13 Register';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR13_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR14_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.LongName = 'ADCD1VCR14 Register';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.Description = 'Value of the VCR14 Register';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR14_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR15_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.LongName = 'ADCD1VCR15 Register';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.Description = 'Value of the VCR15 Register';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR15_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR16_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.LongName = 'ADCD1VCR16 Register';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.Description = 'Value of the VCR16 Register';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR16_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR17_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.LongName = 'ADCD1VCR17 Register';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.Description = 'Value of the VCR17 Register';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR17_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR18_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.LongName = 'ADCD1VCR18 Register';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.Description = 'Value of the VCR18 Register';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR18_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR19_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.LongName = 'ADCD1VCR19 Register';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.Description = 'Value of the VCR19 Register';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR19_CNT_U32.Define = 'Local';


ADC1CFGANDUSE_ADCD1VCR20_CNT_U32 = DataDict.Constant;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.LongName = 'ADCD1VCR20 Register';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.Description = 'Value of the VCR20 Register';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.DocUnits = 'Cnt';
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.EngDT = dt.u32;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.EngVal = 24584;
ADC1CFGANDUSE_ADCD1VCR20_CNT_U32.Define = 'Local';


ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16 = DataDict.Constant;
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.LongName = 'Dynamic Diagnostic Fail Step';
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.Description = 'Dynamic Diagnostic Fail Step';
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.DocUnits = 'Cnt';
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.EngDT = dt.u16;
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.EngVal = 3276;
ADCDIAGC_DYNDIAGFAILSTEP_CNT_U16.Define = 'Local';


ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16 = DataDict.Constant;
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.LongName = 'Dynamic Diagnostic Pass Step';
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.Description = 'Dynamic Diagnostic Pass Step';
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.DocUnits = 'Cnt';
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.EngDT = dt.u16;
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.EngVal = 327;
ADCDIAGC_DYNDIAGPASSSTEP_CNT_U16.Define = 'Local';


APPLCRCREGNNR_CNT_U08 = DataDict.Constant;
APPLCRCREGNNR_CNT_U08.LongName = 'Application CRC Region Number';
APPLCRCREGNNR_CNT_U08.Description = [...
  'The application region"s index might be changed in between programs. T' ...
  'his constant will define the application region for a specific build.'];
APPLCRCREGNNR_CNT_U08.DocUnits = 'Cnt';
APPLCRCREGNNR_CNT_U08.EngDT = dt.u08;
APPLCRCREGNNR_CNT_U08.EngVal = 0;
APPLCRCREGNNR_CNT_U08.Define = 'Local';


BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32 = DataDict.Constant;
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.LongName = 'Battery Return Current Estimated Current Difference Threshold';
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.Description = [...
  'Maximum allowed difference between estimated current (obtained from D ' ...
  'and Q currents calculation) and measured battery return current'];
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.DocUnits = 'Ampr';
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.EngDT = dt.float32;
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.EngVal = 10;
BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32.Define = 'Local';


BATTRTNCURR_FAILSTEP_CNT_U16 = DataDict.Constant;
BATTRTNCURR_FAILSTEP_CNT_U16.LongName = 'Battery Return Current Fail Step';
BATTRTNCURR_FAILSTEP_CNT_U16.Description = [...
  'Increments the error accumulator. Time to fail assert.'];
BATTRTNCURR_FAILSTEP_CNT_U16.DocUnits = 'Cnt';
BATTRTNCURR_FAILSTEP_CNT_U16.EngDT = dt.u16;
BATTRTNCURR_FAILSTEP_CNT_U16.EngVal = 3276;
BATTRTNCURR_FAILSTEP_CNT_U16.Define = 'Local';


BATTRTNCURR_FASTLOOPPROC_CNT_LOGL = DataDict.Constant;
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.LongName = 'Battery Return Current Fast Loop Process';
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.Description = [...
  'Controls the conditional code compilation according to the chosen exec' ...
  'ution case- inside motor ISR or inside 2ms periodic'];
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.DocUnits = 'Cnt';
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.EngDT = dt.lgc;
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.EngVal = 1;
BATTRTNCURR_FASTLOOPPROC_CNT_LOGL.Define = 'Local';


BATTRTNCURR_FILCUTFREQ_HZ_F32 = DataDict.Constant;
BATTRTNCURR_FILCUTFREQ_HZ_F32.LongName = 'Battery Return Current Filter Cutoff Frequency';
BATTRTNCURR_FILCUTFREQ_HZ_F32.Description = [...
  'Filter cutoff frequency when filtering the difference between measured' ...
  ' current and provided estimation'];
BATTRTNCURR_FILCUTFREQ_HZ_F32.DocUnits = 'Hz';
BATTRTNCURR_FILCUTFREQ_HZ_F32.EngDT = dt.float32;
BATTRTNCURR_FILCUTFREQ_HZ_F32.EngVal = 10;
BATTRTNCURR_FILCUTFREQ_HZ_F32.Define = 'Local';


BATTRTNCURR_GAIN_AMPRPERVOLT_F32 = DataDict.Constant;
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.LongName = 'Battery Return Current Gain';
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.Description = 'Used during input conversion';
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.DocUnits = 'AmprPerVolt';
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.EngDT = dt.float32;
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.EngVal = 100;
BATTRTNCURR_GAIN_AMPRPERVOLT_F32.Define = 'Local';


BATTRTNCURR_LOWRTHD_AMPR_F32 = DataDict.Constant;
BATTRTNCURR_LOWRTHD_AMPR_F32.LongName = 'Battery Return Current Lower Threshold';
BATTRTNCURR_LOWRTHD_AMPR_F32.Description = [...
  'Used after sample conversion to amps for range check'];
BATTRTNCURR_LOWRTHD_AMPR_F32.DocUnits = 'Ampr';
BATTRTNCURR_LOWRTHD_AMPR_F32.EngDT = dt.float32;
BATTRTNCURR_LOWRTHD_AMPR_F32.EngVal = -200;
BATTRTNCURR_LOWRTHD_AMPR_F32.Define = 'Local';


BATTRTNCURR_OFFSET_VOLT_F32 = DataDict.Constant;
BATTRTNCURR_OFFSET_VOLT_F32.LongName = 'Battery Return Current Offset';
BATTRTNCURR_OFFSET_VOLT_F32.Description = 'Used during input conversion';
BATTRTNCURR_OFFSET_VOLT_F32.DocUnits = 'Volt';
BATTRTNCURR_OFFSET_VOLT_F32.EngDT = dt.float32;
BATTRTNCURR_OFFSET_VOLT_F32.EngVal = 2.5;
BATTRTNCURR_OFFSET_VOLT_F32.Define = 'Local';


BATTRTNCURR_OUTPMAX_AMPR_F32 = DataDict.Constant;
BATTRTNCURR_OUTPMAX_AMPR_F32.LongName = 'Battery Return Current Output Max';
BATTRTNCURR_OUTPMAX_AMPR_F32.Description = 'Used for output signal saturation';
BATTRTNCURR_OUTPMAX_AMPR_F32.DocUnits = 'Ampr';
BATTRTNCURR_OUTPMAX_AMPR_F32.EngDT = dt.float32;
BATTRTNCURR_OUTPMAX_AMPR_F32.EngVal = 200;
BATTRTNCURR_OUTPMAX_AMPR_F32.Define = 'Local';


BATTRTNCURR_OUTPMIN_AMPR_F32 = DataDict.Constant;
BATTRTNCURR_OUTPMIN_AMPR_F32.LongName = 'Battery Return Current Output Min';
BATTRTNCURR_OUTPMIN_AMPR_F32.Description = 'Used for output signal saturation';
BATTRTNCURR_OUTPMIN_AMPR_F32.DocUnits = 'Ampr';
BATTRTNCURR_OUTPMIN_AMPR_F32.EngDT = dt.float32;
BATTRTNCURR_OUTPMIN_AMPR_F32.EngVal = -200;
BATTRTNCURR_OUTPMIN_AMPR_F32.Define = 'Local';


BATTRTNCURR_PASSSTEP_CNT_U16 = DataDict.Constant;
BATTRTNCURR_PASSSTEP_CNT_U16.LongName = 'Battery Return Current Pass Step';
BATTRTNCURR_PASSSTEP_CNT_U16.Description = [...
  'Decrements the error accumulator. Time to pass assert.'];
BATTRTNCURR_PASSSTEP_CNT_U16.DocUnits = 'Cnt';
BATTRTNCURR_PASSSTEP_CNT_U16.EngDT = dt.u16;
BATTRTNCURR_PASSSTEP_CNT_U16.EngVal = 1638;
BATTRTNCURR_PASSSTEP_CNT_U16.Define = 'Local';


BATTRTNCURR_UPPRTHD_AMPR_F32 = DataDict.Constant;
BATTRTNCURR_UPPRTHD_AMPR_F32.LongName = 'Battery Return Current Upper Threshold';
BATTRTNCURR_UPPRTHD_AMPR_F32.Description = [...
  'Used after sample conversion to amps for range check'];
BATTRTNCURR_UPPRTHD_AMPR_F32.DocUnits = 'Ampr';
BATTRTNCURR_UPPRTHD_AMPR_F32.EngDT = dt.float32;
BATTRTNCURR_UPPRTHD_AMPR_F32.EngVal = 200;
BATTRTNCURR_UPPRTHD_AMPR_F32.Define = 'Local';


BATTVLTGSCAGFAC_ULS_F32 = DataDict.Constant;
BATTVLTGSCAGFAC_ULS_F32.LongName = 'Battery Voltage';
BATTVLTGSCAGFAC_ULS_F32.Description = [...
  'Inverse hardware scaling factor of battery voltage.  .EngVal = (20+3.4' ...
  '8)/3.48;'];
BATTVLTGSCAGFAC_ULS_F32.DocUnits = 'Uls';
BATTVLTGSCAGFAC_ULS_F32.EngDT = dt.float32;
BATTVLTGSCAGFAC_ULS_F32.EngVal = 6.747126437;
BATTVLTGSCAGFAC_ULS_F32.Define = 'Local';


BATTVLTGSWD1SCAGFAC_ULS_F32 = DataDict.Constant;
BATTVLTGSWD1SCAGFAC_ULS_F32.LongName = 'Battery Voltage Switched 1 Scaling Factor';
BATTVLTGSWD1SCAGFAC_ULS_F32.Description = [...
  'Inverse hardware scaling factor of battery voltage switched 1.  .EngVa' ...
  'l = (100+42.2)/42.2'];
BATTVLTGSWD1SCAGFAC_ULS_F32.DocUnits = 'Uls';
BATTVLTGSWD1SCAGFAC_ULS_F32.EngDT = dt.float32;
BATTVLTGSWD1SCAGFAC_ULS_F32.EngVal = 3.369668246;
BATTVLTGSWD1SCAGFAC_ULS_F32.Define = 'Local';


BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM = DataDict.Constant;
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.LongName = 'Desired Initialization Index Not Present';
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.Description = [...
  'This constant is used as NTC number. NTC DesIninIdxNotPrsnt is set in ' ...
  'CF081A and determines if NVM containing the Desired Initialization Ind' ...
  'ex has been written during manufacturing process. The NTC may be set o' ...
  'nly during Initialization of the component. However it may be cleared ' ...
  'in triggered service that is a part of the CF081A (server runnable).'];
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.DocUnits = 'Cnt';
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.EngDT = enum.NtcNr1;
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E5;
BMWTUNSETHNDLR_DESININIDXNOTPRSNT_CNT_ENUM.Define = 'Local';


BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM = DataDict.Constant;
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.LongName = 'Desired Initialization Optional Set A Index Not Present';
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.Description = [...
  'This constant is used as NTC number. NTC DesIninOptSetAIdxNotPrsnt is ' ...
  'set in CF081A and determines if NVM containing the Desired Initializat' ...
  'ion Index has been written during manufacturing process. The NTC may b' ...
  'e set only during Initialization of the component. However it may be c' ...
  'leared in triggered service that is a part of the CF081A (server runna' ...
  'ble).'];
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.DocUnits = 'Cnt';
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.EngDT = enum.NtcNr1;
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E6;
BMWTUNSETHNDLR_DESININOPTSETAISXNOTPRSNT_CNT_ENUM.Define = 'Local';


DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM = DataDict.Constant;
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.LongName = 'Diagnostic Manager List of Latching Type NTC';
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.Description = [...
  'Array of 20 - Contains a list of NTCs that are latch capable. NtcNrWit' ...
  'hResd1.NTCNR_RESD == 0'];
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.DocUnits = 'Cnt';
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.EngDT = enum.NtcNrWithResd1;
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.EngVal =  ...
   [0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0                0];
DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM.Define = 'Local';


DIAGCMGRNTCLTCHCNTRTHD_CNT_U08 = DataDict.Constant;
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.LongName = 'Diagnostic Manager Latch Counter Threshold';
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.Description = [...
  'Array of 20 - Contains a list of threshold for NTCs that are latch cap' ...
  'able'];
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.DocUnits = 'Cnt';
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.EngDT = dt.u08;
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.EngVal =  ...
   [255              255              255              255              255              255              255              255              255              255              255              255              255              255              255              255              255              255              255              255];
DIAGCMGRNTCLTCHCNTRTHD_CNT_U08.Define = 'Local';


ECUTMEAS_DFTT_DEGCGRD_F32 = DataDict.Constant;
ECUTMEAS_DFTT_DEGCGRD_F32.LongName = 'Default Temperature Used in Fault Cases';
ECUTMEAS_DFTT_DEGCGRD_F32.Description = 'Default Temp for fault conditions';
ECUTMEAS_DFTT_DEGCGRD_F32.DocUnits = 'DegCgrd';
ECUTMEAS_DFTT_DEGCGRD_F32.EngDT = dt.float32;
ECUTMEAS_DFTT_DEGCGRD_F32.EngVal = 60;
ECUTMEAS_DFTT_DEGCGRD_F32.Define = 'Local';


ECUTMEAS_ECUTX_VOLT_U3P13 = DataDict.Constant;
ECUTMEAS_ECUTX_VOLT_U3P13.LongName = 'Ecu Temperature X Table';
ECUTMEAS_ECUTX_VOLT_U3P13.Description = [...
  'This is the X table used as part of a linear interpolation to         ' ...
  'translate input analog measurements in volts to temperature'];
ECUTMEAS_ECUTX_VOLT_U3P13.DocUnits = 'Volt';
ECUTMEAS_ECUTX_VOLT_U3P13.EngDT = dt.u3p13;
ECUTMEAS_ECUTX_VOLT_U3P13.EngVal =  ...
   [0.1115            1.324          1.33025           1.3365          1.34275            1.349          1.35525           1.3615];
ECUTMEAS_ECUTX_VOLT_U3P13.Define = 'Local';


ECUTMEAS_ECUTY_DEGCGRD_S8P7 = DataDict.Constant;
ECUTMEAS_ECUTY_DEGCGRD_S8P7.LongName = 'Ecu Temperature Y Table';
ECUTMEAS_ECUTY_DEGCGRD_S8P7.Description = [...
  'This is the Y table used as part of a linear interpolation to         ' ...
  'translate input analog measurements in volts to temperature'];
ECUTMEAS_ECUTY_DEGCGRD_S8P7.DocUnits = 'DegCgrd';
ECUTMEAS_ECUTY_DEGCGRD_S8P7.EngDT = dt.s8p7;
ECUTMEAS_ECUTY_DEGCGRD_S8P7.EngVal =  ...
   [-50              144              145              146              147              148              149              150];
ECUTMEAS_ECUTY_DEGCGRD_S8P7.Define = 'Local';


ECUTMEAS_FILTAU_HZ_F32 = DataDict.Constant;
ECUTMEAS_FILTAU_HZ_F32.LongName = 'Temperature Software Filter Time Constant';
ECUTMEAS_FILTAU_HZ_F32.Description = [...
  'Sets the time constant for filtering the temperature measurement'];
ECUTMEAS_FILTAU_HZ_F32.DocUnits = 'Hz';
ECUTMEAS_FILTAU_HZ_F32.EngDT = dt.float32;
ECUTMEAS_FILTAU_HZ_F32.EngVal = 100;
ECUTMEAS_FILTAU_HZ_F32.Define = 'Local';


ECUTMEAS_NTC0X045FAILSTEP_CNT_U16 = DataDict.Constant;
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.LongName = 'Error Accumulator Test Step Size for Failed Ecu Temperature Test';
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.Description = 'Increments the error accumulator';
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.DocUnits = 'Cnt';
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.EngDT = dt.u16;
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.EngVal = 3000;
ECUTMEAS_NTC0X045FAILSTEP_CNT_U16.Define = 'Local';


ECUTMEAS_NTC0X045PASSSTEP_CNT_U16 = DataDict.Constant;
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.LongName = 'Error Accumulator Test Step Size for Pass Ecu Temperature Test';
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.Description = 'Decrements the error accumulator';
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.DocUnits = 'Cnt';
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.EngDT = dt.u16;
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.EngVal = 3000;
ECUTMEAS_NTC0X045PASSSTEP_CNT_U16.Define = 'Local';


ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32 = DataDict.Constant;
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.LongName = 'Diagnostic Maximum Temperature Limit';
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.Description = [...
  'Identifies the max temperature allowed to accumulate a diagnostic erro' ...
  'r'];
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.DocUnits = 'DegCgrd';
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.EngDT = dt.float32;
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.EngVal = 125;
ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32.Define = 'Local';


ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32 = DataDict.Constant;
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.LongName = 'Diagnostic Minimum Temperature Limit';
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.Description = [...
  'Identifies the min temperature allowed to accumulate a diagnostic erro' ...
  'r'];
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.DocUnits = 'DegCgrd';
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.EngDT = dt.float32;
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.EngVal = -40;
ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32.Define = 'Local';


ELECGLBPRM_IVTRCNT_CNT_U08 = DataDict.Constant;
ELECGLBPRM_IVTRCNT_CNT_U08.LongName = 'Inverter Count';
ELECGLBPRM_IVTRCNT_CNT_U08.Description = 'Number of Inverters';
ELECGLBPRM_IVTRCNT_CNT_U08.DocUnits = 'Cnt';
ELECGLBPRM_IVTRCNT_CNT_U08.EngDT = dt.u08;
ELECGLBPRM_IVTRCNT_CNT_U08.EngVal = 1;
ELECGLBPRM_IVTRCNT_CNT_U08.Define = 'Local';


ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08 = DataDict.Constant;
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.LongName = 'Motor Control Interrupt Trigger Source';
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.Description = [...
  'This signal allows a configuration of the type of MotCtrlISR source.  ' ...
  'The thought here is that various FDDs may be affected by this decision' ...
  ' so its setting is of a global nature.  Via implementation if  ELECGLB' ...
  'PRM_MOTCTRLINTRPTTRIGSRC_CNT_U08 == ELECGLBPRM_MOTCTRLINTRPTTRIGCFGx_C' ...
  'NT_U08 the generation of peak interrupt is enabled.  For purposes of t' ...
  'his FDD:  ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.EngVal = 0, the inre' ...
  'rrupt generation is disabled.'];
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.DocUnits = 'Cnt';
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.EngDT = dt.u08;
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.EngVal = 0;
ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08.Define = 'Global';


ELECGLBPRM_PWMFRQMAX_HZ_U32 = DataDict.Constant;
ELECGLBPRM_PWMFRQMAX_HZ_U32.LongName = 'Maximum PWM Frequency';
ELECGLBPRM_PWMFRQMAX_HZ_U32.Description = [...
  'High end of PWM frequency dither range'];
ELECGLBPRM_PWMFRQMAX_HZ_U32.DocUnits = 'Hz';
ELECGLBPRM_PWMFRQMAX_HZ_U32.EngDT = dt.u32;
ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal = 18000;
ELECGLBPRM_PWMFRQMAX_HZ_U32.Define = 'Local';


ELECGLBPRM_PWMFRQMIN_HZ_U32 = DataDict.Constant;
ELECGLBPRM_PWMFRQMIN_HZ_U32.LongName = 'Minimum PWM Frequency';
ELECGLBPRM_PWMFRQMIN_HZ_U32.Description = [...
  'High end of PWM frequency dither range'];
ELECGLBPRM_PWMFRQMIN_HZ_U32.DocUnits = 'Hz';
ELECGLBPRM_PWMFRQMIN_HZ_U32.EngDT = dt.u32;
ELECGLBPRM_PWMFRQMIN_HZ_U32.EngVal = 14000;
ELECGLBPRM_PWMFRQMIN_HZ_U32.Define = 'Local';


ELECGLBPRM_PWMPERDMAX_NANOSEC_U32 = DataDict.Constant;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.LongName = 'Maximum PWM Period';
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.Description = [...
  'Maximum PWM period in units of NanoSec.  ELECGLBPRM_PWMPERDMAX_NANOSEC' ...
  '_U32.EngVal = 1e9/ELECGLBPRM_PWMFRQMIN_HZ_U32.EngVal.  EngMin = 1e9/22' ...
  'e3, EngMax = 1e9/14e3'];
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.DocUnits = 'NanoSec';
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.EngDT = dt.u32;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.EngVal = 71429;
ELECGLBPRM_PWMPERDMAX_NANOSEC_U32.Define = 'Local';


ELECGLBPRM_PWMPERDMIN_NANOSEC_U32 = DataDict.Constant;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.LongName = 'Minimum PWM Period';
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.Description = [...
  'Minimum PWM period in units of NanoSec.  ELECGLBPRM_PWMPERDMIN_NANOSEC' ...
  '_U32.EngVal = 1e9/ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal.  EngMin = 1e9/22' ...
  'e3, EngMax = 1e9/14e3'];
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.DocUnits = 'NanoSec';
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.EngDT = dt.u32;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.EngVal = 55555;
ELECGLBPRM_PWMPERDMIN_NANOSEC_U32.Define = 'Local';


ELECGLBPRM_PWMPERDNOMX2_SEC_F32 = DataDict.Constant;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.LongName = 'PWM Period Nominal Times 2';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Description = [...
  'This constant is 2 times ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9 in second' ...
  's.'];
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.DocUnits = 'Sec';
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngDT = dt.float32;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.EngVal = 0.000125;
ELECGLBPRM_PWMPERDNOMX2_SEC_F32.Define = 'Local';


ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9 = DataDict.Constant;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.LongName = 'Nominal PWM Period';
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.Description = [...
  'Nominal PWM Period in units of MicroSec.  ELECGLBPRM_PWMPERDNOM_MICROS' ...
  'EC_U7P9 = (2 * 1e6)/(ELECGLBPRM_PWMFRQMAX_HZ_U32.EngVal + ELECGLBPRM_P' ...
  'WMFRQMIN_HZ_U32.EngVal).  EngMin = 1e6/22e3, EngMax = 1e6/14e3'];
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.DocUnits = 'MicroSec';
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.EngDT = dt.u7p9;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.EngVal = 62.5;
ELECGLBPRM_PWMPERDNOM_MICROSEC_U7P9.Define = 'Local';


FLTINJENA = DataDict.Constant;
FLTINJENA.LongName = 'Fault Injection Enable';
FLTINJENA.Description = [...
  'This is false for production builds.  It is set to true at compile tim' ...
  'e only for s/w special builds with fault injection active.'];
FLTINJENA.DocUnits = 'Cnt';
FLTINJENA.EngDT = dt.lgc;
FLTINJENA.EngVal = 0;
FLTINJENA.Define = 'Local';


GATEDRV0FETFLTMTGTNENA_ULS_LOGL = DataDict.Constant;
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.LongName = 'Field effect transistor fault mitigation enable';
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.Description = [...
  'When this is enabled, the gate drive component will notify the system ' ...
  'when a FET fault is detected.'];
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.DocUnits = 'Uls';
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.EngDT = dt.lgc;
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.EngVal = 1;
GATEDRV0FETFLTMTGTNENA_ULS_LOGL.Define = 'Local';


HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 4 Ntc Number';
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.Description = 'HwTq4 Ntc Number';
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X073;
HWTQ4MEAS_HWTQ4RNGCHKPRTCLNTCNR_CNT_ENUM.Define = 'Local';


HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 4 Manufacturing Ntc Number';
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.Description = 'HwTq4 Manufacturing Ntc Number';
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E0;
HWTQ4MEAS_HWTQ4SCANOTPRFMMFGNTCNR_CNT_ENUM.Define = 'Local';


HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 4 Manufacturing Ntc Number';
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.Description = 'HwTq4 Manufacturing Ntc Number';
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E1;
HWTQ4MEAS_HWTQ4TRIMNOTPRFMMFGNTCNR_CNT_ENUM.Define = 'Local';


HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32 = DataDict.Constant;
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.LongName = 'Handwheel Torque Bar Stiffness';
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.Description = 'Handwheel Torque Bar Stiffness';
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.DocUnits = 'NmpDeg';
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.EngDT = dt.float32;
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.EngVal = 2.5;
HWTQ4MEAS_HWTQBARSTFN_NMPDEG_F32.Define = 'Local';


HWTQ4MEAS_HWTQOFFS_VOLT_F32 = DataDict.Constant;
HWTQ4MEAS_HWTQOFFS_VOLT_F32.LongName = 'HandWheel Torque Offset';
HWTQ4MEAS_HWTQOFFS_VOLT_F32.Description = [...
  'Used to Offset the Input Handwheel Torque'];
HWTQ4MEAS_HWTQOFFS_VOLT_F32.DocUnits = 'Volt';
HWTQ4MEAS_HWTQOFFS_VOLT_F32.EngDT = dt.float32;
HWTQ4MEAS_HWTQOFFS_VOLT_F32.EngVal = 2.5;
HWTQ4MEAS_HWTQOFFS_VOLT_F32.Define = 'Local';


HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32 = DataDict.Constant;
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.LongName = 'Handwheel Torque Sensor Scale Nominal Value';
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.Description = [...
  'Nominal Value of Torque Sensor Scale'];
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.DocUnits = 'VoltpDeg';
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.EngDT = dt.float32;
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.EngVal = 0.5;
HWTQ4MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.Define = 'Local';


HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 5 Ntc Number';
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.Description = 'HwTq5 Ntc Number';
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X075;
HWTQ5MEAS_HWTQ5RNGCHKPRTCLNTCNR_CNT_ENUM.Define = 'Local';


HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 5 Manufacturing Ntc Number';
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.Description = 'HwTq5 Manufacturing Ntc Number';
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E2;
HWTQ5MEAS_HWTQ5SCANOTPRFMMFGNTCNR_CNT_ENUM.Define = 'Local';


HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM = DataDict.Constant;
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.LongName = 'Handwheel Torque 5 Manufacturing Ntc Number';
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.Description = 'HwTq5 Manufacturing Ntc Number';
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.DocUnits = 'Cnt';
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X1E3;
HWTQ5MEAS_HWTQ5TRIMNOTPRFMMFGNTCNR_CNT_ENUM.Define = 'Local';


HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32 = DataDict.Constant;
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.LongName = 'Handwheel Torque 5 Measurement Handwheel Torque Bar Stiffness';
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.Description = 'Handwheel Torque Bar Stiffness';
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.DocUnits = 'NmpDeg';
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.EngDT = dt.float32;
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.EngVal = 2.5;
HWTQ5MEAS_HWTQBARSTFN_NMPDEG_F32.Define = 'Local';


HWTQ5MEAS_HWTQOFFS_VOLT_F32 = DataDict.Constant;
HWTQ5MEAS_HWTQOFFS_VOLT_F32.LongName = 'Handwheel Torque 5 Measurement HandWheel Torque Offset';
HWTQ5MEAS_HWTQOFFS_VOLT_F32.Description = [...
  'Used to Offset the Input Handwheel Torque'];
HWTQ5MEAS_HWTQOFFS_VOLT_F32.DocUnits = 'Volt';
HWTQ5MEAS_HWTQOFFS_VOLT_F32.EngDT = dt.float32;
HWTQ5MEAS_HWTQOFFS_VOLT_F32.EngVal = 2.5;
HWTQ5MEAS_HWTQOFFS_VOLT_F32.Define = 'Local';


HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32 = DataDict.Constant;
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.LongName = 'Handwheel Torque 5 Measurement Handwheel Torque Sensor Scale Nominal Value';
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.Description = [...
  'Nominal Value of Torque Sensor Scale'];
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.DocUnits = 'VoltpDeg';
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.EngDT = dt.float32;
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.EngVal = 0.5;
HWTQ5MEAS_HWTQSNSRSCANOMVAL_VOLTPDEG_F32.Define = 'Local';


MCUDIAGCERRINJ = DataDict.Constant;
MCUDIAGCERRINJ.LongName = 'MCU Diagnostic Error Injection';
MCUDIAGCERRINJ.Description = [...
  'This is false for production builds.  It is set to true at compile tim' ...
  'e only for s/w special builds with MCU Error Injection active.'];
MCUDIAGCERRINJ.DocUnits = 'Cnt';
MCUDIAGCERRINJ.EngDT = dt.lgc;
MCUDIAGCERRINJ.EngVal = 0;
MCUDIAGCERRINJ.Define = 'Local';


MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM = DataDict.Constant;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 0 Protocol Fault NTC Number';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 0 Protocol Fault NTC Number'];
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X083;
MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM.Define = 'Local';


MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM = DataDict.Constant;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.LongName = 'Motor Angle 1 Protocol Fault NTC Number';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Description = [...
  'Motor Angle 1 Protocol Fault NTC Number'];
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.DocUnits = 'Cnt';
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngDT = enum.NtcNr1;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.EngVal = NtcNr1.NTCNR_0X085;
MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM.Define = 'Local';


MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08 = DataDict.Constant;
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.LongName = 'Motor Angle 3 Sensor Relevant Bit Width Expansion';
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.Description = [...
  'Number of bits necessary to expand Motor Position Sensor raw result si' ...
  'gnificant bits to cover full range of u0p16 data type'];
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.DocUnits = 'Cnt';
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.EngDT = dt.u08;
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.EngVal = 4;
MOTAG3MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.Define = 'Local';


MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08 = DataDict.Constant;
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.LongName = 'Motor Angle 4 Sensor Relevant Bit Width Expansion';
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.Description = [...
  'Number of bits necessary to expand Motor Position Sensor raw result si' ...
  'gnificant bits to cover full range of u0p16 data type'];
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.DocUnits = 'Cnt';
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.EngDT = dt.u08;
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.EngVal = 4;
MOTAG4MEAS_SNSRRLVBITWIDTHEXP_CNT_U08.Define = 'Local';


RVSBATTPROTN_FAILSTEP_CNT_U16 = DataDict.Constant;
RVSBATTPROTN_FAILSTEP_CNT_U16.LongName = 'Reverese Battery Protection Fail Step';
RVSBATTPROTN_FAILSTEP_CNT_U16.Description = [...
  'Debounce NTC set strategy step towards FAIL status'];
RVSBATTPROTN_FAILSTEP_CNT_U16.DocUnits = 'Cnt';
RVSBATTPROTN_FAILSTEP_CNT_U16.EngDT = dt.u16;
RVSBATTPROTN_FAILSTEP_CNT_U16.EngVal = 6552;
RVSBATTPROTN_FAILSTEP_CNT_U16.Define = 'Local';


RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32 = DataDict.Constant;
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.LongName = 'Reverse Battery Protection Ground Measured Voltage High Limitation';
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.Description = [...
  'Maximum allowed signal level for ground related measures'];
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.DocUnits = 'Volt';
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.EngDT = dt.float32;
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.EngVal = 1.5;
RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32.Define = 'Local';


RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32 = DataDict.Constant;
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.LongName = 'Reverse Battery Protection Ground Measured Voltage Low Limitation';
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.Description = [...
  'Minimum allowed signal level for ground related measures'];
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.DocUnits = 'Volt';
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.EngDT = dt.float32;
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.EngVal = 1.1;
RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32.Define = 'Local';


RVSBATTPROTN_PASSSTEP_CNT_U16 = DataDict.Constant;
RVSBATTPROTN_PASSSTEP_CNT_U16.LongName = 'Reverese Battery Protection Pass Step';
RVSBATTPROTN_PASSSTEP_CNT_U16.Description = [...
  'Debounce NTC set strategy step towards PASS status'];
RVSBATTPROTN_PASSSTEP_CNT_U16.DocUnits = 'Cnt';
RVSBATTPROTN_PASSSTEP_CNT_U16.EngDT = dt.u16;
RVSBATTPROTN_PASSSTEP_CNT_U16.EngVal = 3276;
RVSBATTPROTN_PASSSTEP_CNT_U16.Define = 'Local';


RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32 = DataDict.Constant;
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.LongName = 'Reverse Battery Protection Return Measured Voltage High Limitation';
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.Description = [...
  'Maximum allowed signal level for battery return related measures'];
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.DocUnits = 'Volt';
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.EngDT = dt.float32;
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.EngVal = 1.5;
RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32.Define = 'Local';


RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32 = DataDict.Constant;
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.LongName = 'Reverse Battery Protection Return Measured Voltage Low Limitation';
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.Description = [...
  'Minimum allowed signal level for battery return related measures'];
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.DocUnits = 'Volt';
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.EngDT = dt.float32;
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.EngVal = 0.12;
RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32.Define = 'Local';


RVSBATTPROTN_RVSFLTTHD_VOLT_F32 = DataDict.Constant;
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.LongName = 'Reverse Battery Protection - Reverse Fault Threshold';
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.Description = [...
  'Threshold level for detection of MOSFET malfunction'];
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.DocUnits = 'Volt';
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.EngDT = dt.float32;
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.EngVal = 0.6;
RVSBATTPROTN_RVSFLTTHD_VOLT_F32.Define = 'Local';


SWPENA = DataDict.Constant;
SWPENA.LongName = 'SWEEP ENABLE';
SWPENA.Description = [...
  'Configuration Parameter to indicate whether Sweep build or not.1=TRUE ' ...
  '0=FALSE. '];
SWPENA.DocUnits = 'Cnt';
SWPENA.EngDT = dt.lgc;
SWPENA.EngVal = 0;
SWPENA.Define = 'Local';


TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32 = DataDict.Constant;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.LongName = 'XCP Vehicle Speed Threshold';
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.Description = [...
  'Vehicle Speed is compared with XCP Vehicle speed threshold to determin' ...
  'e whether to grant or deny requested change in corresponding RAM value' ...
  's.'];
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.DocUnits = 'Kph';
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.EngDT = dt.float32;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.EngVal = 1;
TUNSELNAUTHY_XCPVEHSPDTHD_KPH_F32.Define = 'Local';



%%-------------------------------------------
%% NTC Definition                            
%%-------------------------------------------
%end of Data Dictionary
