#!/usr/local/bin/perl

use strict;
use warnings;

use FindBin;
use lib "$FindBin::Bin/lib";
use mypackage;

print mypackage::mytest();

exit;