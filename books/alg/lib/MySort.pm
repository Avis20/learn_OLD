package MySort;
use uni::perl qw|:dumper|;

my $DEBUG = 1;

my $call = 0;

sub merge_sort {
    my ( $array, $left, $right ) = @_;
    warn "Call = " . ++$call . "; array = @{$array}\n" if $DEBUG;
    warn "left = $left, right = $right\n" if $DEBUG;
    return if $left > $right;

    my $middle = int ( ($right + $left) / 2 );
    warn "middle = $middle\n" if $DEBUG;

    merge_sort( $array, $left, $middle );
    merge_sort( $array, $middle + 1, $right );
}

sub insertion_sort {
    my ( $array, $length ) = @_;
    for (my $i = 1; $i < $length; $i++) {
        warn "i = $i; curr el = $array->[$i]" if $DEBUG;
        my $tmp = $array->[$i];
        my $j = $i - 1;
        while ( $j >= 0 && $array->[$j] > $tmp ){
            warn "index = ".($j + 1)." = $array->[$j]" if $DEBUG;
            $array->[$j + 1] = $array->[$j];
            $j--;
        }
        warn "j = $j" if $DEBUG;
        warn "@{$array}" if $DEBUG;
        $array->[$j + 1] = $tmp;
        warn "@{$array}" if $DEBUG;
        warn "\n" if $DEBUG;
    }
    return @{ $array || [] };
}

sub selection_sort {
    my ( $array, $size ) = @_;
    for (my $i = 0; $i < $size; $i++) {
        warn "i = $i\n" if $ENV{DEBUG};
        my $small = $i;
        warn "i small = $small; el = $array->[$small]\n" if $ENV{DEBUG};
        for (my $j = $i + 1; $j < $size; $j++) {
            warn "j = $j" if $ENV{DEBUG};
            $small = $j if ( $array->[$j] < $array->[$small] );
        }
        warn "j small = $small; el = $array->[$small]\n" if $ENV{DEBUG};
        ( $array->[$i], $array->[$small] ) = ( $array->[$small], $array->[$i] );
    }
    return @{ $array || [] };
}

1;