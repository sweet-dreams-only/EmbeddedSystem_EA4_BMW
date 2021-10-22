# ======================================================================================================================
#      File: iso15765.py
#   Project: Nxtr Python Library
#   Created: 2013-05-01
#  Modified: 2015-12-01
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2013-2015 Neexter Automotive
#
# This library is used to hande the ISO 15765-2 protocol layer also known as "transport".  This layer sits atop the
# target hardware (e.g. Peak, VN1630, etc.) and is responsible for breaking messages into multiple CAN frames.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2013-05-01  1     Jared     Initial file creation
# ----------------------------------------------------------------------------------------------------------------------

# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
from ctypes import *
import pcanbasic as PCB
import time
import logging


class CANTimeout(Exception):
    pass


# -----[ Transport Object ]---------------------------------------------------------------------------------------------
# @brief    Basic Object for sending and receiving single of multi-frame can messages.
class Transport(object):
    # -----[ Initialization Function ]----------------------------------------------------------------------------------
    # @brief    Initialize the Peak USB CAN tool to communicate with EPS system by default.  You may pass parameters to
    #           configure the Peak tool differently.
    # @param    channel     (Optional) PCAN channel to use for communication with the USB tool. (Default: 1)
    # @param    baud        (Optional) PCAN enumerated baud rate.  See PCANBasic for more information. (Default: 500k)
    # @param    reqId       (Optional) Request ID - ID which all requests are sent on. (Default: 0x730)
    # @param    respId      (Optional) Response ID - ID for which all responses shall be received. (Default: 0x738)
    def __init__(self, channel=PCB.PCAN_USBBUS1, baud=PCB.PCAN_BAUD_500K, reqId=0x730, respId=0x738):
        self.channel = channel
        self.baud = baud
        self.reqId = reqId
        self.respId = respId
        self.pcan = PCB.PCANBasic()
        self.pcan.Initialize(channel, baud)
        self.pcan.FilterMessages(channel, min(reqId, respId), max(reqId, respId), PCB.PCAN_MODE_STANDARD)
        self.pcan.Reset(channel)
        self.stmin = 0
    
    # -----[ Send Frame Function ]--------------------------------------------------------------------------------------
    # @brief    Transmit a single 8 byte frame.  Do not call this function directly, instead use request which will
    #           handle separation of messages longer than 7 bytes into multiple frames.
    # @param    data    Array of data to transmit up to 8 bytes in length - less than 8 will be padded with zeros.
    # @return   Error code from PCAN tool is error occurred or zero if no error.
    def _sendFrame(self, data):
        if len(data) > 8:
            raise ReferenceError('Single frame length cannot exceed 8 bytes')
        buf = PCB.TPCANMsg()
        buf.ID = self.reqId
        buf.LEN = 8
        buf.MSGTYPE = PCB.PCAN_MESSAGE_STANDARD
        for idx in range(8):
            if idx < len(data):
                buf.DATA[idx] = data[idx]
            else:
                buf.DATA[idx] = 0
        logging.debug("TX: %s" % repr(dict(ID=hex(buf.ID), MSGTYPE=buf.MSGTYPE, LEN=buf.LEN, DATA=list(hex(v) for v in buf.DATA))))
        # print "TX: %s" % repr(dict(ID=hex(buf.ID), MSGTYPE=buf.MSGTYPE, LEN=buf.LEN, DATA=list(hex(v) for v in buf.DATA)))
        error = self.pcan.Write(self.channel, buf)
        if error != 0:
            logging.error('0x%X: %s' % (error, self.pcan.GetErrorText(error)[1]))
        return error
    
    # -----[ Get Frame Function ]---------------------------------------------------------------------------------------
    # @brief    Get a single frame of 8 bytes from the PCAN tool buffer.  The timeout will allow a determinate wait time
    #           before giving up on reception.  Do not call this function directly, instead call the response function
    #           which will assemble single and multi-frame responses into a nice format.
    # @param    timeout     Timeout in seconds - set to zero to disable timeout and wait forever.
    # @return   Response data if received of None if timeout occurred.
    def _getFrame(self, timeout):
        startTime = time.time()
        while True:
            resp = self.pcan.Read(self.channel)
            if resp[1].ID == self.respId:
                # print "RX: %s" % repr(dict(ID=hex(resp[1].ID), MSGTYPE=resp[1].MSGTYPE, LEN=resp[1].LEN, DATA=list(hex(v) for v in resp[1].DATA)))
                logging.debug("RX: %s" % repr(dict(ID=hex(resp[1].ID), MSGTYPE=resp[1].MSGTYPE, LEN=resp[1].LEN, DATA=list(hex(v) for v in resp[1].DATA))))
                return resp[1].DATA
            elif timeout != 0 and (time.time() - startTime) > timeout:
                raise CANTimeout
    
    # -----[ Wait To Continue Function ]--------------------------------------------------------------------------------
    # @brief    Helper function to parse responses until a type 3 (continuation) response is received with a status of
    #           0 (Clear to Send).  Will only wait for response until timeout has been reached if timeout was given as
    #           value other than zero.
    # @param    timeout     Timeout in seconds - set to zero to disable timeout and wait forever.
    # @return   Boolean True if response was received or False if timeout occurred.
    def _waitToContinue(self, timeout):
        startTime = time.time()
        while True:
            data = self._getFrame(timeout)
            type = (data[0] >> 4) & 0x0F
            status = data[0] & 0x0F
            if type == 3 and status == 0:
                stmin = data[2]
                self.stmin = float(stmin) * 0.001
                return True
            elif timeout != 0 and (time.time() - startTime) > timeout:
                return False
    
    # -----[ Request Data Function ]------------------------------------------------------------------------------------
    # @brief    Send a load of data on the CAN bus.  This function will split the data into multiple frames if
    #           necessary.
    # @param    data        List of data to send out on the can bus.  Arbitrary length.
    # @return   timeout     (Optional) Timeout in seconds for the response to multi-frame initialization in the case of
    #                       a multi-frame transmission.  This parameter has no effect on transmisions less than 7 bytes.
    #                       (Default: 1 second timeout)
    def request(self, data, timeout=1):
        if len(data) <= 7:
            buf = [len(data)]
            buf.extend(data)
            self._sendFrame(buf)
        elif len(data) < 4096:
            buf = [0x10 | ((len(data) >> 8) & 0x0F), (len(data) & 0xFF)]
            position = 0
            counter = 0
            for i in range(6):
                buf.append(data[position])
                position += 1
            self._sendFrame(buf)
            if self._waitToContinue(timeout):
                while position < len(data):
                    counter = (counter + 1) & 0x0F
                    buf = [0x20 | counter]
                    for i in range(7):
                        if position < len(data):
                            value = data[position]
                        else:
                            value = 0
                        buf.append(value)
                        position += 1
                    self._sendFrame(buf)
                    separationStart = time.time()
                    while time.time() < self.stmin + separationStart:
                        pass
        
    
    # -----[ Response Data Function ]-----------------------------------------------------------------------------------
    # @brief    Read response data from the CAN bus.  Multi-frame messages will automatically be concatenated together
    #           into a single list response.
    # @param    timeout     (Optional) Timeout in seconds to wait for response data.  Set to zero to disable th timeout
    #                       and wait forever. (Default: 1 second timeout)
    # @return   List of data read from the CAN bus with matching reqId.
    def response(self, timeout=1):
        msg = self._getFrame(timeout)
        type = msg[0] >> 4
        data = None
        if type == 0:
            # single frame response (0)
            length = msg[0]
            data = []
            for i in range(length):
                data.append(msg[i + 1])
        elif type == 1:
            # multi-frame response (1)
            length = ((msg[0] & 0x0F) << 8) | msg[1]
            data = msg[2:]
            cnt = 0
            # send continuation frame (3)
            self._sendFrame([0x30])
            # receive continuation frames (2)
            while len(data) < length:
                msg = self._getFrame(timeout)
                cnt = (cnt + 1) & 0x0F
                type = msg[0] >> 4
                index = msg[0] & 0x0F
                if type != 2:
                    print "Type %d received, expedted type 2" % type
                    break
                elif index != cnt:
                    print "Index %d doesn't match counter %d" % (index, cnt)
                    break
                for i in range(7):
                    data.append(msg[i + 1])
                    if len(data) >= length:
                        break
            # TODO: perhaps a timeout would be smart
        elif type == 0x0F: # XCP
            data = []
            for i in range(8):
                data.append(msg[i])
        else:
            print "Unknown type %d" % type
        return data


# End of File: iso15765.py