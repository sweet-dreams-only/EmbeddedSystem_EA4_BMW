<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<AUTOSAR xmlns="http://autosar.org/schema/r4.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://autosar.org/schema/r4.0 AUTOSAR_4-2-2.xsd">
  <AR-PACKAGES>
    <AR-PACKAGE>
      <SHORT-NAME>ActiveEcuC</SHORT-NAME>
      <ELEMENTS>
        <ECUC-MODULE-CONFIGURATION-VALUES>
          <SHORT-NAME>Dcm</SHORT-NAME>
          <DEFINITION-REF DEST="ECUC-MODULE-DEF">/MICROSAR/Dcm</DEFINITION-REF>
          <IMPLEMENTATION-CONFIG-VARIANT>VARIANT-PRE-COMPILE</IMPLEMENTATION-CONFIG-VARIANT>
          <MODULE-DESCRIPTION-REF DEST="BSW-IMPLEMENTATION">/MICROSAR/Dcm_Impl</MODULE-DESCRIPTION-REF>
          <CONTAINERS>
            <ECUC-CONTAINER-VALUE>
              <SHORT-NAME>DcmConfigSet</SHORT-NAME>
              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet</DEFINITION-REF>
              <SUB-CONTAINERS>
                <ECUC-CONTAINER-VALUE>
                  <SHORT-NAME>DcmDsp</SHORT-NAME>
                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp</DEFINITION-REF>
                  <SUB-CONTAINERS>
                    % for routine in routines:
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspRoutineInfo_CmnMfgSrv_Srv${'%04X' % routine.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo</DEFINITION-REF>
                        <SUB-CONTAINERS>
                          <ECUC-CONTAINER-VALUE>
                            <SHORT-NAME>DcmDspRoutineAuthorization</SHORT-NAME>
                            <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineAuthorization</DEFINITION-REF>
                            <REFERENCE-VALUES>
                              <ECUC-REFERENCE-VALUE>
                                <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineAuthorization/DcmDspRoutineSessionRef</DEFINITION-REF>
                                <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspSession/DcmDspSessionRow_DEFAULT_SESSION</VALUE-REF>
                              </ECUC-REFERENCE-VALUE>
                              <ECUC-REFERENCE-VALUE>
                                <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineAuthorization/DcmDspRoutineSessionRef</DEFINITION-REF>
                                <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspSession/DcmDspSessionRow_NXTRMFG</VALUE-REF>
                              </ECUC-REFERENCE-VALUE>
                            </REFERENCE-VALUES>
                          </ECUC-CONTAINER-VALUE>
                          % if routine.start and routine.start.in_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspStartRoutineIn</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineIn</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspStartRoutineInSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineIn/DcmDspStartRoutineInSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineIn/DcmDspStartRoutineInSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.start.in_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineIn/DcmDspStartRoutineInSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineIn/DcmDspStartRoutineInSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                          % if routine.start and routine.start.out_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspStartRoutineOut</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineOut</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspStartRoutineOutSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineOut/DcmDspStartRoutineOutSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineOut/DcmDspStartRoutineOutSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.start.out_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineOut/DcmDspStartRoutineOutSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspStartRoutineOut/DcmDspStartRoutineOutSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                          % if routine.stop and routine.stop.in_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspRoutineStopIn</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopIn</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspRoutineStopInSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopIn/DcmDspRoutineStopInSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopIn/DcmDspRoutineStopInSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.stop.in_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopIn/DcmDspRoutineStopInSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopIn/DcmDspRoutineStopInSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                          % if routine.stop and routine.stop.out_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspRoutineStopOut</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopOut</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspRoutineStopOutSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopOut/DcmDspRoutineStopOutSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopOut/DcmDspRoutineStopOutSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.stop.out_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopOut/DcmDspRoutineStopOutSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineStopOut/DcmDspRoutineStopOutSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                          % if routine.result and routine.result.in_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspRoutineRequestResIn</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResIn</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspRoutineRequestResInSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResIn/DcmDspRoutineRequestResInSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResIn/DcmDspRoutineRequestResInSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.result.in_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResIn/DcmDspRoutineRequestResInSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResIn/DcmDspRoutineRequestResInSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                          % if routine.result and routine.result.out_length > 0:
                            <ECUC-CONTAINER-VALUE>
                              <SHORT-NAME>DcmDspRoutineRequestResOut</SHORT-NAME>
                              <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResOut</DEFINITION-REF>
                              <SUB-CONTAINERS>
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspRoutineRequestResOutSignal</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResOut/DcmDspRoutineRequestResOutSignal</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResOut/DcmDspRoutineRequestResOutSignal/DcmDspRoutineSignalLength</DEFINITION-REF>
                                      <VALUE>${routine.result.out_length}</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResOut/DcmDspRoutineRequestResOutSignal/DcmDspRoutineSignalPos</DEFINITION-REF>
                                      <VALUE>0</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo/DcmDspRoutineRequestResOut/DcmDspRoutineRequestResOutSignal/DcmDspRoutineSignalType</DEFINITION-REF>
                                      <VALUE>UINT8</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              </SUB-CONTAINERS>
                            </ECUC-CONTAINER-VALUE>
                          % endif
                        </SUB-CONTAINERS>
                      </ECUC-CONTAINER-VALUE>
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspRoutine_CmnMfgSrv_Srv${'%04X' % routine.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine</DEFINITION-REF>
                        <PARAMETER-VALUES>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRequestResultsRoutineSupported</DEFINITION-REF>
                            <VALUE>${'true' if routine.result is not None else 'false'}</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRoutineIdentifier</DEFINITION-REF>
                            <VALUE>${routine.sid}</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRoutineUsePort</DEFINITION-REF>
                            <VALUE>false</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRoutineUsed</DEFINITION-REF>
                            <VALUE>true</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspStopRoutineSupported</DEFINITION-REF>
                            <VALUE>${'true' if routine.stop is not None else 'false'}</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRoutineFixedLength</DEFINITION-REF>
                            <VALUE>false</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-TEXTUAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspStartRoutineFnc</DEFINITION-REF>
                            <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % routine.sid}Strt</VALUE>
                          </ECUC-TEXTUAL-PARAM-VALUE>
                          % if routine.stop is not None:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspStopRoutineFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % routine.sid}Stop</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif;
                          % if routine.result is not None:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRequestResultsRoutineFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % routine.sid}Sts</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif;
                        </PARAMETER-VALUES>
                        <REFERENCE-VALUES>
                          <ECUC-REFERENCE-VALUE>
                            <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutine/DcmDspRoutineInfoRef</DEFINITION-REF>
                            <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspRoutineInfo_CmnMfgSrv_Srv${'%04X' % routine.sid}</VALUE-REF>
                          </ECUC-REFERENCE-VALUE>
                        </REFERENCE-VALUES>
                      </ECUC-CONTAINER-VALUE>
                    % endfor;
                    % for service in iocs + pids:
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspDataInfo_CmnMfgSrv_Srv${'%04X' % service.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDataInfo</DEFINITION-REF>
                        <PARAMETER-VALUES>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDataInfo/DcmDspDataFixedLength</DEFINITION-REF>
                            <VALUE>true</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                        </PARAMETER-VALUES>
                      </ECUC-CONTAINER-VALUE>
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspData_CmnMfgSrv_Srv${'%04X' % service.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData</DEFINITION-REF>
                        <PARAMETER-VALUES>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataSize</DEFINITION-REF>
                            <VALUE>${service.length}</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-TEXTUAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataUsePort</DEFINITION-REF>
                            <VALUE>USE_DATA_ASYNCH_FNC</VALUE>
                          </ECUC-TEXTUAL-PARAM-VALUE>
                          <ECUC-TEXTUAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataType</DEFINITION-REF>
                            <VALUE>UINT8</VALUE>
                          </ECUC-TEXTUAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed</DEFINITION-REF>
                            <VALUE>false</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          % if service.read:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReadFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % service.sid}Rd</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif
                          % if service.write:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataWriteFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % service.sid}Wr</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif
                          % if service.release:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataReturnControlToEcuFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % service.sid}Rtn</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif
                          % if service.take:
                            <ECUC-TEXTUAL-PARAM-VALUE>
                              <DEFINITION-REF DEST="ECUC-FUNCTION-NAME-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataShortTermAdjustmentFnc</DEFINITION-REF>
                              <VALUE>CmnMfgSrvIf_Srv0x${'%04X' % service.sid}Adj</VALUE>
                            </ECUC-TEXTUAL-PARAM-VALUE>
                          % endif;
                        </PARAMETER-VALUES>
                        <REFERENCE-VALUES>
                          <ECUC-REFERENCE-VALUE>
                            <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataInfoRef</DEFINITION-REF>
                            <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspDataInfo_CmnMfgSrv_Srv${'%04X' % service.sid}</VALUE-REF>
                          </ECUC-REFERENCE-VALUE>
                        </REFERENCE-VALUES>
                      </ECUC-CONTAINER-VALUE>
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspDidInfo_CmnMfgSrv_Srv${'%04X' % service.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo</DEFINITION-REF>
                        <PARAMETER-VALUES>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidDynamicallyDefined</DEFINITION-REF>
                            <VALUE>false</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                        </PARAMETER-VALUES>
                        <SUB-CONTAINERS>
                          <ECUC-CONTAINER-VALUE>
                            <SHORT-NAME>DcmDspDidAccess</SHORT-NAME>
                            <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess</DEFINITION-REF>
                            <SUB-CONTAINERS>
                              % if service in iocs:
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspDidControl</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl</DEFINITION-REF>
                                  <PARAMETER-VALUES>
                                    <ECUC-TEXTUAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidControlMask</DEFINITION-REF>
                                      <VALUE>DCM_CONTROLMASK_INTERNAL</VALUE>
                                    </ECUC-TEXTUAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidFreezeCurrentState</DEFINITION-REF>
                                      <VALUE>false</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidResetToDefault</DEFINITION-REF>
                                      <VALUE>false</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidReturnControlToEcu</DEFINITION-REF>
                                      <VALUE>true</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                    <ECUC-NUMERICAL-PARAM-VALUE>
                                      <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidShortTermAdjustment</DEFINITION-REF>
                                      <VALUE>true</VALUE>
                                    </ECUC-NUMERICAL-PARAM-VALUE>
                                  </PARAMETER-VALUES>
                                  <REFERENCE-VALUES>
                                    <ECUC-REFERENCE-VALUE>
                                      <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidControl/DcmDspDidControlSessionRef</DEFINITION-REF>
                                      <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspSession/DcmDspSessionRow_NXTRMFG</VALUE-REF>
                                    </ECUC-REFERENCE-VALUE>
                                  </REFERENCE-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              % endif;
                              % if service.read:
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspDidRead</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidRead</DEFINITION-REF>
                                  <REFERENCE-VALUES>
                                    <ECUC-REFERENCE-VALUE>
                                      <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidRead/DcmDspDidReadSessionRef</DEFINITION-REF>
                                      <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspSession/DcmDspSessionRow_NXTRMFG</VALUE-REF>
                                    </ECUC-REFERENCE-VALUE>
                                  </REFERENCE-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              % endif;
                              % if service.write:
                                <ECUC-CONTAINER-VALUE>
                                  <SHORT-NAME>DcmDspDidWrite</SHORT-NAME>
                                  <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidWrite</DEFINITION-REF>
                                  <REFERENCE-VALUES>
                                    <ECUC-REFERENCE-VALUE>
                                      <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidWrite/DcmDspDidWriteSessionRef</DEFINITION-REF>
                                      <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspSession/DcmDspSessionRow_NXTRMFG</VALUE-REF>
                                    </ECUC-REFERENCE-VALUE>
                                  </REFERENCE-VALUES>
                                </ECUC-CONTAINER-VALUE>
                              % endif;
                            </SUB-CONTAINERS>
                          </ECUC-CONTAINER-VALUE>
                        </SUB-CONTAINERS>
                      </ECUC-CONTAINER-VALUE>
                      <ECUC-CONTAINER-VALUE>
                        <SHORT-NAME>DcmDspDid_CmnMfgSrv_Srv${'%04X' % service.sid}</SHORT-NAME>
                        <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid</DEFINITION-REF>
                        <PARAMETER-VALUES>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidIdentifier</DEFINITION-REF>
                            <VALUE>${service.sid}</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-NUMERICAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidUsed</DEFINITION-REF>
                            <VALUE>true</VALUE>
                          </ECUC-NUMERICAL-PARAM-VALUE>
                          <ECUC-TEXTUAL-PARAM-VALUE>
                            <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidUsePort</DEFINITION-REF>
                            <VALUE>USE_DATA_ELEMENT_SPECIFIC_INTERFACES</VALUE>
                          </ECUC-TEXTUAL-PARAM-VALUE>
                        </PARAMETER-VALUES>
                        <REFERENCE-VALUES>
                          <ECUC-REFERENCE-VALUE>
                            <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidInfoRef</DEFINITION-REF>
                            <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo_CmnMfgSrv_Srv${'%04X' % service.sid}</VALUE-REF>
                          </ECUC-REFERENCE-VALUE>
                        </REFERENCE-VALUES>
                        <SUB-CONTAINERS>
                          <ECUC-CONTAINER-VALUE>
                            <SHORT-NAME>DcmDspDidSignal</SHORT-NAME>
                            <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal</DEFINITION-REF>
                            <PARAMETER-VALUES>
                              <ECUC-NUMERICAL-PARAM-VALUE>
                                <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataPos</DEFINITION-REF>
                                <VALUE>0</VALUE>
                              </ECUC-NUMERICAL-PARAM-VALUE>
                            </PARAMETER-VALUES>
                            <REFERENCE-VALUES>
                              <ECUC-REFERENCE-VALUE>
                                <DEFINITION-REF DEST="ECUC-REFERENCE-DEF">/MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataRef</DEFINITION-REF>
                                <VALUE-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DcmDspData_CmnMfgSrv_Srv${'%04X' % service.sid}</VALUE-REF>
                              </ECUC-REFERENCE-VALUE>
                            </REFERENCE-VALUES>
                          </ECUC-CONTAINER-VALUE>
                        </SUB-CONTAINERS>
                      </ECUC-CONTAINER-VALUE>
                    % endfor;
                  </SUB-CONTAINERS>
                </ECUC-CONTAINER-VALUE>
              </SUB-CONTAINERS>
            </ECUC-CONTAINER-VALUE>
          </CONTAINERS>
        </ECUC-MODULE-CONFIGURATION-VALUES>
      </ELEMENTS>
    </AR-PACKAGE>
  </AR-PACKAGES>
</AUTOSAR>
