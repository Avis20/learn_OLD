package MySearch;
use uni::perl qw|:dumper|;

sub binary_search {
    my ( $array, $length, $item ) = @_;
    my ( $left, $right ) = ( 0, $length );
    while ( $left <= $right ){
        my $middle = int ( ($right + $left) / 2 );
        return $middle if $array->[$middle] == $item;
        $array->[$middle] > $item ? $right = $middle : $left = $middle++;
    }
    return 'not found';
}

sub recursive_linear_search {
    my ( $array, $length, $index, $item ) = @_;
    return 'not found' if $index > $length;
    return $index if $array->[$index] == $item;
    return recursive_linear_search($array, $length, ++$index, $item);
}

sub sentinel_linear_search {
    my ( $array, $length, $item ) = @_;
    return $length - 1 if $array->[$length - 1] == $item;
    $array->[$length - 1] = $item;
    my $index = 0;
    while ( $array->[$index] != $item ){
        $index++;
    }
    return $index if $index < $length - 1;
    return 'not found';
}

sub better_linear_search {
    my ( $array, $length, $item ) = @_;
    for (my $i = 0; $i < $length; $i++){
        return $i if $array->[$i] == $item;
    }
    return 'not found';
}

sub linear_search {
    my ( $array, $length, $item ) = @_;
    my $answer = 'not found';
    for (my $i = 0; $i < $length; $i++) {
        $answer = $i if $array->[$i] == $item;
    }
    return $answer;
}

1;