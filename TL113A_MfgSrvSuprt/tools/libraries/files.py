# ======================================================================================================================
#      File: services.py
#   Project: EA4 Manufacturing Services
#   Created: 2017-07-28
#  Modified: 2017-07-28
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# This shared resource is used when parsing services from an ODX file.  Invoking the service class and passing a
# service instance and base variant to the constructor is all that is needed to parse a service into handy Python
# objects.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2017-07-28  1     Jared     Initial file creation using original function from OdxGen.py
# ----------------------------------------------------------------------------------------------------------------------
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import os


# ======================================================================================================================
# Library Functions
# ----------------------------------------------------------------------------------------------------------------------
def backup(filename):
    """This function will rename a filename to a backup version so that it is preserved for external comparison.
    This operation also negates the need to remove read-only attributes from files as the original (with whatever
    attributes it has) is not modified."""
    def bak_name(index):
        if index < 1:
            return filename
        folder, file = os.path.split(filename)
        file = '%s.%d.bak' % (file, index)
        return os.path.join(folder, file)
    def exists(index):
        file = bak_name(index)
        return os.path.exists(file)
    def rename(index):
        backname = bak_name(index)
        os.rename(filename, backname)
    def backup(index=0):
        if exists(index):
            backup(index + 1)
        else:
            rename(index)
    if os.path.exists(filename):
        backup()


# End of File: files.py