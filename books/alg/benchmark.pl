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

timethese(0, {
    'binary' => sub {
        my $item = int rand @array;
        my $index = MySearch::binary_search( \@array, $length, $item );
        ok( $item == $array[$index] ) if $check;
    },
    # 'linear' => sub {
    #     my $item = int rand @array;
    #     my $index = MySearch::linear_search( \@array, $length, $item );
    #     ok( $item == $array[$index] ) if $check;
    # },
    # 'better' => sub {
    #     my $item = int rand @array;
    #     my $index = MySearch::better_linear_search( \@array, $length, $item );
    #     ok( $item == $array[$index] ) if $check;
    # },
    # 'sentinel' => sub {
    #     my $item = int rand @array;
    #     my $index = MySearch::sentinel_linear_search( \@array, $length, $item );
    #     ok( $item == $array[$index] ) if $check;
    # },
    # 'reqursive' => sub {
    #     my $item = int rand @array;
    #     my $index = MySearch::recursive_linear_search( \@array, $length, 0, $item );
    #     ok( $item == $array[$index] ) if $check;
    # },
});

done_testing() if $check; 

exit;