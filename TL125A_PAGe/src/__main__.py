# ======================================================================================================================
#      File: __main__.py
#   Project: Python AUTOSAR generator
#   Created: 2018-02-14
#  Modified: 2018-02-14
#    Author: Kevin Smith & Jared Julien
#     Email: kevin.smith@nexteer.com
# Copyright: (c) 2018 Nxtr Automotive
#
#   Purpose: This file was created because python cannot handle the page components being relative to the python 
#            installation. The __main__ file is a direct copy from the files delivered by BMW, but instead of using 
#            '.command', this file uses 'page.command' to properly locate the files needed by python to execute.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  ==========================================================================================
# 2018-02-14  1     KJS     Initial file creation in synergy                                                   EA4#20630
# ----------------------------------------------------------------------------------------------------------------------

import sys
from page.command import Command

sys.exit(Command().run())

# End of file