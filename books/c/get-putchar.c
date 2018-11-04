#include <stdio.h>

// копирование входного потока в выходной

int main(){
    char c;
    
    while ( (c = getchar()) != EOF )
        putchar(c);

    return 0;
}