#!"C:\Program Files (x86)\Python36-32\python.exe"
# EASY-INSTALL-ENTRY-SCRIPT: 'page==1.1.1','console_scripts','page'
__requires__ = 'page==1.1.1'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('page==1.1.1', 'console_scripts', 'page')()
    )
