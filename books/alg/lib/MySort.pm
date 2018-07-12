package MySort;
use uni::perl qw|:dumper|;

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
    return $array;
}

1;