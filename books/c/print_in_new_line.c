#include <stdio.h>

int main(){

    char c;

    while ( (c = getchar()) != EOF )
        if ( c != '\n' ) printf("%c\n", c);

    return 0;
}