#!/usr/local/bin/perl

use lib::abs        qw| ./lib |;
use uni::perl       qw| :dumper |;
use List::Util      qw| shuffle |;
use Benchmark;
use Test::More;

use MySearch;

my ( $shuffle, $check, $size ) = (0, 0, 999999);

my @array = $shuffle ? shuffle (0..$size) : (0..$size);
my $length = scalar(@array);

timethese(100, {
    'binary' => sub {
        my $item = int rand @array;
        my $index = MySearch::binary_search( \@array, $length, $item );
        ok( $item == $array[$index] ) if $check;
    },
});

done_testing() if $check; 

exit;