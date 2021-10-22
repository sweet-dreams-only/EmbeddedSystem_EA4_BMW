# This "library" was created to emulate the behavior of the AUTOSAR compliant CRC16 module when computing CRC16
# checksums for Nxtr Manufacturing Services.

class CRC16(object):
    def __init__(self, initial=0xFFFF, polynomial=0x1021):
        self.initial = initial
        self.polynomial = polynomial

    def calculate(self, input_data=None):
        crcValue = self.initial
        for c in input_data:
            crcValue = (crcValue ^ (c << 8)) & 0xFFFF
            for i in range(8):
                if crcValue & 0x8000:
                    crcValue = ((crcValue << 1) ^ self.polynomial) & 0xFFFF
                else:
                    crcValue = (crcValue << 1) & 0xFFFF
        return crcValue


# End of File: __init__.py