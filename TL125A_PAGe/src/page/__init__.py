#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
from .command import Command
from .pgenfile import File

def main():
    return Command().run()
