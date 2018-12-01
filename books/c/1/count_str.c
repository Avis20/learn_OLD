#include <stdio.h>

// подсчет кол-ва строк в входном потоке

int main(){

    long count = 0;
    char c;

    while ( (c = getchar()) != EOF )
        if ( c == '\n' )
            ++count;

    printf("%ld\n", count);

    return 0;
}