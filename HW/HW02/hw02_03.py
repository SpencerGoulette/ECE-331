#!/usr/bin/python

import sys
import os

# Check to see if single file is passed
# Find number of lines in file
lines = 0
if(len(sys.argv[0:]) == 2):
    try:
        f = open(sys.argv[1],'r')
        for l in f.readlines():
            lines = lines + 1
        f.close()
        print "Lines in file: {}".format(lines)
    except:
        print "Cannot open",sys.argv[1]

else:
    print "./hw02_03 filename"
