#include <stdio.h>
#include "ref.h"

void sub(){
    int x = 1, y = 2, z[10];
    int *ip;

    ip = &x;
    y = *ip;
}

