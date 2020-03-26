#!/usr/bin/python
import os

path = 'reccar/'
files = sorted(os.listdir(path))

for name in files:
    try:
        f = open(os.path.join(path, name), 'r')
        file = name[:name.find(' UTC')]
	print file,
        winds = ""
	data = f.read()
        katahdin = data[data.find('MOUNT KATAHDIN'):data.find('$$')].upper().replace("\n"," ")
        if katahdin.find('MPH') != -1:
            winds = katahdin[katahdin.find('MPH') - 10:katahdin.find('MPH')]
            if winds.find('TO') == -1:
                winds = winds[winds.find('MPH') - 4:]
            if winds[:1].isalpha():
                winds = winds[1:]
        if winds[:1] == " ":
            winds = winds[1:]
        if winds[:] == "":
            print "0 0"
        else:
	    wind = winds.replace("  "," ")
	    print wind.replace(" TO "," ")

        f.close()
    except:
        print "Cannot open",name
