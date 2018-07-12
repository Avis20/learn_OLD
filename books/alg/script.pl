#!/usr/local/bin/perl

use lib::abs        qw| ./lib |;
use uni::perl       qw| :dumper |;
use List::Util      qw| shuffle |;
use Benchmark;
use Test::More;

use MySearch;
use MySort;

my @arr = (12, 9, 3, 7, 14, 11);
my $length = scalar(@arr);
my $sort_arr = MySort::selection_sort(\@arr, $length);
warn dumper $sort_arr;
warn dumper [sort { $a > $b } @arr];

=head

my ( $shuffle, $check, $size ) = (0, 1, 99);

my @array = $shuffle ? shuffle (0..$size) : (0..$size);
my $length = scalar(@array);

my $item = int rand @array;
my $index = MySearch::recursive_binary_search( \@array, 0, $length, $item );
warn "item = $item; index = $index; check = $array[$index]" if $check;
ok( $item == $array[$index] ) if $check;

done_testing() if $check;

exit;