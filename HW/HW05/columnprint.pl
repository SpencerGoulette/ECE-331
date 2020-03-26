#!/usr/bin/perl

# Opens file passed on command line
open(F, '<', $ARGV[0]) or die $!;

# Checks to make sure right amount of arguments passed
if($#ARGV + 1 == 2 and $ARGV[1] > 0 and $ARGV[1]) {
	# Splits each line by a comma
	# Then prints the correct column
	# -1 used so 1 prints first column and not zero 
	while(<F>) {
		@columns = split /,/, $_;
		print $columns[$ARGV[1] - 1] . "\n";
	}
}

# If not used correctly print usage
else {
	print "Usage: ./columnprint.pl (filename) (positive field number)\n"
}

close(F);


