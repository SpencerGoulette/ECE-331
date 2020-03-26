#!/usr/bin/python

import numpy
from matplotlib import pyplot as plt
from datetime import datetime

# Opens the data file with the formatted data, time, and wind speeds
try:
	f = open("/home/pi/ECE331/HW/HW04/data.txt",'r')
except:
	print "Couldn't open file"
	pass

# Loads the data from the text file then close file
data = numpy.loadtxt(f,dtype=int)

f.close()

# Creates datetimes and puts in array (year, month, day, hour, minute, second)
time = []
for i in range(len(data[:,1])):
	dates = datetime(data[i][0],data[i][1],data[i][2],data[i][3],data[i][4],data[i][5])
	time.append(dates)

# Plot the wind speeds
plt.plot(time,data[:,6],time,data[:,7])
plt.title("Top of Mount Katahdin Wind Speeds")
plt.xlabel("Dates")
plt.ylabel("Wind Speeds in mph")
plt.legend("Min Wind Speeds","Max Wind Speeds")

plt.show()
