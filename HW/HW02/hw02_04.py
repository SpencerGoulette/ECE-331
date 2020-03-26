#!/usr/bin/python

import sys
import os

# Check to see if single file is passed
# Reverse the contents of the file
string = ""
if(len(sys.argv[0:]) == 2):
    try:
        f = open(sys.argv[1],'r')
        for l in reversed(f.read()):
            string = string + l
        print string
        f.close()
    except:
        print "Cannot open",sys.argv[1]

else:
    print "python hw02_04.py filename"
