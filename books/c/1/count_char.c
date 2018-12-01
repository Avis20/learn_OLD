#include <stdio.h>

// подсчет кол-ва символов в входном потоке

int main(){

    long count = 0;
    while ( getchar() != EOF )
        ++count;
    printf("%ld", count);

    return 0;
}