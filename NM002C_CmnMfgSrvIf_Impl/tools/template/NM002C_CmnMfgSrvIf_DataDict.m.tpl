%%-----------------------------------------------------------------------%
%% EA4 Component Data Dictionary - Created on 08-Jan-2018 11:12:38       %
%%                                 Created with tool release: 3.1.0      %
%%                                 Synergy file: %version: X %           %
%%                                 Derived by: %derived_by: X %          %
%%-----------------------------------------------------------------------%

NM002C = DataDict.FDD;
NM002C.Version = '1.0.X';
NM002C.LongName = 'Common Manufacturing Service Interface';
NM002C.ShoName  = 'CmnMfgSrvIf';
NM002C.DesignASIL = 'QM';
NM002C.Description = [...
  'Interface between DCM component and NM001A to provide Nxtr common m' ...
  'anufacturing services to programs that must put Nxtr services throu' ...
  'gh DCM (such as with Flexray).'];



%%-------------------------------------------
%% Runnable Definitions                      
%%-------------------------------------------
CmnMfgSrvIfInit1 = DataDict.Runnable;
CmnMfgSrvIfInit1.Context = 'Rte';
CmnMfgSrvIfInit1.TimeStep = 0;
CmnMfgSrvIfInit1.Description = 'Dummy init function.';

% for runnable in runnables:
${runnable.name} = DataDict.SrvRunnable;
${runnable.name}.Context = 'NonRte';
${runnable.name}.Description = 'Runnable for DCM service to call - in turn invokes NM001A through MaiFct.';
${runnable.name}.Return = DataDict.CSReturn;
${runnable.name}.Return.Type = 'Standard';
${runnable.name}.Return.Min = 0;
${runnable.name}.Return.Max = 1;
${runnable.name}.Return.TestTolerance = 0;<% arg_num = 1 %>
% if runnable.has_input:
${runnable.name}.Arguments(${arg_num}) = DataDict.CSArguments;
${runnable.name}.Arguments(${arg_num}).Name = '${runnable.input_name}';
${runnable.name}.Arguments(${arg_num}).EngDT = dt.u08;
${runnable.name}.Arguments(${arg_num}).EngMin = 0;
${runnable.name}.Arguments(${arg_num}).EngMax = 255;
${runnable.name}.Arguments(${arg_num}).TestTolerance = 0;
${runnable.name}.Arguments(${arg_num}).Units = 'Cnt';
${runnable.name}.Arguments(${arg_num}).Direction = 'InOut';
${runnable.name}.Arguments(${arg_num}).InitRowCol = [1  ${runnable.input_length}];
${runnable.name}.Arguments(${arg_num}).Description = 'None';<% arg_num += 1 %>
% endif;
${runnable.name}.Arguments(${arg_num}) = DataDict.CSArguments;
${runnable.name}.Arguments(${arg_num}).Name = 'OpStatus';
${runnable.name}.Arguments(${arg_num}).EngDT = dt.u08;
${runnable.name}.Arguments(${arg_num}).EngMin = 0;
${runnable.name}.Arguments(${arg_num}).EngMax = 255;
${runnable.name}.Arguments(${arg_num}).Units = 'Cnt';
${runnable.name}.Arguments(${arg_num}).Direction = 'In';
${runnable.name}.Arguments(${arg_num}).InitRowCol = [1  1];
${runnable.name}.Arguments(${arg_num}).Description = 'None';<% arg_num += 1 %>
% if runnable.has_output:
${runnable.name}.Arguments(${arg_num}) = DataDict.CSArguments;
${runnable.name}.Arguments(${arg_num}).Name = '${runnable.output_name}';
${runnable.name}.Arguments(${arg_num}).EngDT = dt.u08;
${runnable.name}.Arguments(${arg_num}).EngMin = 0;
${runnable.name}.Arguments(${arg_num}).EngMax = 255;
${runnable.name}.Arguments(${arg_num}).TestTolerance = 0;
${runnable.name}.Arguments(${arg_num}).Units = 'Cnt';
${runnable.name}.Arguments(${arg_num}).Direction = 'Out';
${runnable.name}.Arguments(${arg_num}).InitRowCol = [1  ${runnable.output_length}];
${runnable.name}.Arguments(${arg_num}).Description = 'None';<% arg_num += 1 %>
% endif;
% if runnable.has_error:
${runnable.name}.Arguments(${arg_num}) = DataDict.CSArguments;
${runnable.name}.Arguments(${arg_num}).Name = 'ErrorCode';
${runnable.name}.Arguments(${arg_num}).EngDT = dt.u08;
${runnable.name}.Arguments(${arg_num}).EngMin = 0;
${runnable.name}.Arguments(${arg_num}).EngMax = 255;
${runnable.name}.Arguments(${arg_num}).TestTolerance = 0;
${runnable.name}.Arguments(${arg_num}).Units = 'Cnt';
${runnable.name}.Arguments(${arg_num}).Direction = 'Out';
${runnable.name}.Arguments(${arg_num}).InitRowCol = [1  1];
${runnable.name}.Arguments(${arg_num}).Description = 'None';
% endif;


% endfor;


%%-------------------------------------------
%% Client Definitions                        
%%-------------------------------------------
CmnMfgSrvMaiFct = DataDict.Client;
CmnMfgSrvMaiFct.CallLocation = {'${"','".join(runnable.name for runnable in runnables)}'};
CmnMfgSrvMaiFct.Description = [...
  'Common manufacturing services (NM001A) main function.  Provides common' ...
  ' entry point for invoking Nxtr manufacturing services.'];
CmnMfgSrvMaiFct.Return = DataDict.CSReturn;
CmnMfgSrvMaiFct.Return.Type = 'None';
CmnMfgSrvMaiFct.Return.Min = [];
CmnMfgSrvMaiFct.Return.Max = [];
CmnMfgSrvMaiFct.Return.TestTolerance = [];
CmnMfgSrvMaiFct.Arguments(1) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(1).Name = 'SrvId';
CmnMfgSrvMaiFct.Arguments(1).EngDT = dt.u08;
CmnMfgSrvMaiFct.Arguments(1).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(1).EngMax = 255;
CmnMfgSrvMaiFct.Arguments(1).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(1).Direction = 'In';
CmnMfgSrvMaiFct.Arguments(1).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(1).Description = 'None';
CmnMfgSrvMaiFct.Arguments(2) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(2).Name = 'SubFct';
CmnMfgSrvMaiFct.Arguments(2).EngDT = dt.u08;
CmnMfgSrvMaiFct.Arguments(2).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(2).EngMax = 255;
CmnMfgSrvMaiFct.Arguments(2).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(2).Direction = 'In';
CmnMfgSrvMaiFct.Arguments(2).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(2).Description = 'None';
CmnMfgSrvMaiFct.Arguments(3) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(3).Name = 'PrmId';
CmnMfgSrvMaiFct.Arguments(3).EngDT = dt.u16;
CmnMfgSrvMaiFct.Arguments(3).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(3).EngMax = 65535;
CmnMfgSrvMaiFct.Arguments(3).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(3).Direction = 'In';
CmnMfgSrvMaiFct.Arguments(3).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(3).Description = 'None';
CmnMfgSrvMaiFct.Arguments(4) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(4).Name = 'DataBufferPtr';
CmnMfgSrvMaiFct.Arguments(4).EngDT = dt.u08;
CmnMfgSrvMaiFct.Arguments(4).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(4).EngMax = 255;
CmnMfgSrvMaiFct.Arguments(4).TestTolerance = 0;
CmnMfgSrvMaiFct.Arguments(4).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(4).Direction = 'InOut';
CmnMfgSrvMaiFct.Arguments(4).InitRowCol = [65535      1];
CmnMfgSrvMaiFct.Arguments(4).Description = 'None';
CmnMfgSrvMaiFct.Arguments(5) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(5).Name = 'ReqLen';
CmnMfgSrvMaiFct.Arguments(5).EngDT = dt.u16;
CmnMfgSrvMaiFct.Arguments(5).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(5).EngMax = 4095;
CmnMfgSrvMaiFct.Arguments(5).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(5).Direction = 'In';
CmnMfgSrvMaiFct.Arguments(5).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(5).Description = 'None';
CmnMfgSrvMaiFct.Arguments(6) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(6).Name = 'RespLen';
CmnMfgSrvMaiFct.Arguments(6).EngDT = dt.u16;
CmnMfgSrvMaiFct.Arguments(6).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(6).EngMax = 4095;
CmnMfgSrvMaiFct.Arguments(6).TestTolerance = 0;
CmnMfgSrvMaiFct.Arguments(6).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(6).Direction = 'Out';
CmnMfgSrvMaiFct.Arguments(6).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(6).Description = 'None';
CmnMfgSrvMaiFct.Arguments(7) = DataDict.CSArguments;
CmnMfgSrvMaiFct.Arguments(7).Name = 'RespCod';
CmnMfgSrvMaiFct.Arguments(7).EngDT = dt.u08;
CmnMfgSrvMaiFct.Arguments(7).EngMin = 0;
CmnMfgSrvMaiFct.Arguments(7).EngMax = 255;
CmnMfgSrvMaiFct.Arguments(7).TestTolerance = 0;
CmnMfgSrvMaiFct.Arguments(7).Units = 'Cnt';
CmnMfgSrvMaiFct.Arguments(7).Direction = 'Out';
CmnMfgSrvMaiFct.Arguments(7).InitRowCol = [1  1];
CmnMfgSrvMaiFct.Arguments(7).Description = 'None';



%%-------------------------------------------
%% Input Signal Definition                   
%%-------------------------------------------

%%-------------------------------------------
%% Output Signal Definition                  
%%-------------------------------------------

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
%%end of Data Dictionary
