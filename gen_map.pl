#!/usr/bin/perl

use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
    		print "o";
	}
	else {
		print "."; 
	}
     print "\n"; 
}