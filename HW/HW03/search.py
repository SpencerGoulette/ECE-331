#!/usr/bin/python
import re
import sys

for l in sys.stdin.readlines():
    m = re.search('^([1-9][0-9]*)*[02468]$',l)
    print m


