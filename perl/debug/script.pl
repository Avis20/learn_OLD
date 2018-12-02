#!/usr/local/bin/perl

use uni::perl       qw| :dumper |;

print "Hello";
print "world";

test();

sub test {
    print 1;
}

exit;