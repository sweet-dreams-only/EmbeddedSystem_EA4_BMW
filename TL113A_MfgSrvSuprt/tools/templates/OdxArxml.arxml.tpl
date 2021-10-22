<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<AUTOSAR xmlns="http://autosar.org/schema/r4.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://autosar.org/schema/r4.0 autosar_4-0-3.xsd">
  <AR-PACKAGES>
    <AR-PACKAGE>
      <SHORT-NAME>ActiveEcuC</SHORT-NAME>
      <ELEMENTS>
        <ECUC-MODULE-CONFIGURATION-VALUES>
          <SHORT-NAME>NxtrMfgSrv</SHORT-NAME>
          <DEFINITION-REF DEST="ECUC-MODULE-DEF">/Nxtr/NxtrMfgSrv</DEFINITION-REF>
          <IMPLEMENTATION-CONFIG-VARIANT>VARIANT-PRE-COMPILE</IMPLEMENTATION-CONFIG-VARIANT>
          <CONTAINERS>
            % for service in services:
              % if service.getType() == 0x2A:
                <% continue %>
              % endif;
              <ECUC-CONTAINER-VALUE>
                <SHORT-NAME>${service.title()}</SHORT-NAME>
                <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/${variant}</DEFINITION-REF>
                <PARAMETER-VALUES>
                  <ECUC-TEXTUAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/ServiceType</DEFINITION-REF>
                    <VALUE>${service.type()}</VALUE>
                  </ECUC-TEXTUAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/RequestLength</DEFINITION-REF>
                    <VALUE>${service.reqLen()}</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/ResponseLength</DEFINITION-REF>
                    <VALUE>${service.respLen()}</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  % if service.serviceId() is not None:
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/ServiceId</DEFINITION-REF>
                      <VALUE>${service.serviceId()}</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                  % endif;
                  % if service.subFunction() is not None:
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/SubFunction</DEFINITION-REF>
                      <VALUE>${service.subFunction()}</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                  % endif;
                </PARAMETER-VALUES>
                <SUB-CONTAINERS>
                  <ECUC-CONTAINER-VALUE>
                    <SHORT-NAME>AccessControls</SHORT-NAME>
                    <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/${variant}/AccessControls</DEFINITION-REF>
                    <PARAMETER-VALUES>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/AccessControls/NxtrSession</DEFINITION-REF>
                        <VALUE>${str(service.nexteerSession()).lower()}</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/AccessControls/SecurityAccess</DEFINITION-REF>
                        <VALUE>${str(service.securityAccess()).lower()}</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                    </PARAMETER-VALUES>
                  </ECUC-CONTAINER-VALUE>
                </SUB-CONTAINERS>
              </ECUC-CONTAINER-VALUE>
            % endfor;
              <ECUC-CONTAINER-VALUE>
                <SHORT-NAME>SrvPerRdFast</SHORT-NAME>
                <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService</DEFINITION-REF>
                <PARAMETER-VALUES>
                  <ECUC-TEXTUAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ServiceType</DEFINITION-REF>
                    <VALUE>Periodic - 0x2A</VALUE>
                  </ECUC-TEXTUAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/RequestLength</DEFINITION-REF>
                    <VALUE>65535</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ResponseLength</DEFINITION-REF>
                    <VALUE>0</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/SubFunction</DEFINITION-REF>
                      <VALUE>1</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                </PARAMETER-VALUES>
                <SUB-CONTAINERS>
                  <ECUC-CONTAINER-VALUE>
                    <SHORT-NAME>AccessControls</SHORT-NAME>
                    <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls</DEFINITION-REF>
                    <PARAMETER-VALUES>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/NxtrSession</DEFINITION-REF>
                        <VALUE>true</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/SecurityAccess</DEFINITION-REF>
                        <VALUE>false</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                    </PARAMETER-VALUES>
                  </ECUC-CONTAINER-VALUE>
                </SUB-CONTAINERS>
              </ECUC-CONTAINER-VALUE>
              <ECUC-CONTAINER-VALUE>
                <SHORT-NAME>SrvPerRdMed</SHORT-NAME>
                <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService</DEFINITION-REF>
                <PARAMETER-VALUES>
                  <ECUC-TEXTUAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ServiceType</DEFINITION-REF>
                    <VALUE>Periodic - 0x2A</VALUE>
                  </ECUC-TEXTUAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/RequestLength</DEFINITION-REF>
                    <VALUE>65535</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ResponseLength</DEFINITION-REF>
                    <VALUE>0</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/SubFunction</DEFINITION-REF>
                      <VALUE>2</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                </PARAMETER-VALUES>
                <SUB-CONTAINERS>
                  <ECUC-CONTAINER-VALUE>
                    <SHORT-NAME>AccessControls</SHORT-NAME>
                    <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls</DEFINITION-REF>
                    <PARAMETER-VALUES>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/NxtrSession</DEFINITION-REF>
                        <VALUE>true</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/SecurityAccess</DEFINITION-REF>
                        <VALUE>false</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                    </PARAMETER-VALUES>
                  </ECUC-CONTAINER-VALUE>
                </SUB-CONTAINERS>
              </ECUC-CONTAINER-VALUE>
              <ECUC-CONTAINER-VALUE>
                <SHORT-NAME>SrvPerRdSlow</SHORT-NAME>
                <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService</DEFINITION-REF>
                <PARAMETER-VALUES>
                  <ECUC-TEXTUAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ServiceType</DEFINITION-REF>
                    <VALUE>Periodic - 0x2A</VALUE>
                  </ECUC-TEXTUAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/RequestLength</DEFINITION-REF>
                    <VALUE>65535</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ResponseLength</DEFINITION-REF>
                    <VALUE>0</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/SubFunction</DEFINITION-REF>
                      <VALUE>3</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                </PARAMETER-VALUES>
                <SUB-CONTAINERS>
                  <ECUC-CONTAINER-VALUE>
                    <SHORT-NAME>AccessControls</SHORT-NAME>
                    <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls</DEFINITION-REF>
                    <PARAMETER-VALUES>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/NxtrSession</DEFINITION-REF>
                        <VALUE>true</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/SecurityAccess</DEFINITION-REF>
                        <VALUE>false</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                    </PARAMETER-VALUES>
                  </ECUC-CONTAINER-VALUE>
                </SUB-CONTAINERS>
              </ECUC-CONTAINER-VALUE>
              <ECUC-CONTAINER-VALUE>
                <SHORT-NAME>SrvPerRdStop</SHORT-NAME>
                <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService</DEFINITION-REF>
                <PARAMETER-VALUES>
                  <ECUC-TEXTUAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-ENUMERATION-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ServiceType</DEFINITION-REF>
                    <VALUE>Periodic - 0x2A</VALUE>
                  </ECUC-TEXTUAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/RequestLength</DEFINITION-REF>
                    <VALUE>0</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                  <ECUC-NUMERICAL-PARAM-VALUE>
                    <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/ResponseLength</DEFINITION-REF>
                    <VALUE>0</VALUE>
                  </ECUC-NUMERICAL-PARAM-VALUE>
                    <ECUC-NUMERICAL-PARAM-VALUE>
                      <DEFINITION-REF DEST="ECUC-INTEGER-PARAM-DEF">/Nxtr/NxtrMfgSrv/${variant}/SubFunction</DEFINITION-REF>
                      <VALUE>4</VALUE>
                    </ECUC-NUMERICAL-PARAM-VALUE>
                </PARAMETER-VALUES>
                <SUB-CONTAINERS>
                  <ECUC-CONTAINER-VALUE>
                    <SHORT-NAME>AccessControls</SHORT-NAME>
                    <DEFINITION-REF DEST="ECUC-PARAM-CONF-CONTAINER-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls</DEFINITION-REF>
                    <PARAMETER-VALUES>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/NxtrSession</DEFINITION-REF>
                        <VALUE>true</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                      <ECUC-NUMERICAL-PARAM-VALUE>
                        <DEFINITION-REF DEST="ECUC-BOOLEAN-PARAM-DEF">/Nxtr/NxtrMfgSrv/CommonService/AccessControls/SecurityAccess</DEFINITION-REF>
                        <VALUE>false</VALUE>
                      </ECUC-NUMERICAL-PARAM-VALUE>
                    </PARAMETER-VALUES>
                  </ECUC-CONTAINER-VALUE>
                </SUB-CONTAINERS>
              </ECUC-CONTAINER-VALUE>
          </CONTAINERS>
        </ECUC-MODULE-CONFIGURATION-VALUES>
      </ELEMENTS>
    </AR-PACKAGE>
  </AR-PACKAGES>
</AUTOSAR>
