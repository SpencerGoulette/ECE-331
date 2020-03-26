#!/usr/bin/perl

# Checks to see if valid file is passed
# If file not valid, then stat returns a list with 0 elements
# Goes through each file passed and check that the number of hardlinks is greater than 1
# If hardlinks are greater than 1 then prints the filename and number of hardlinks
foreach $filename(@ARGV) {
	print($filename . " is not valid\n") if ((stat($filename)) == 0);
	print($filename . " has " . (stat($filename))[3] . " hardlinks\n") if ((stat($filename))[3] > 1);
}
