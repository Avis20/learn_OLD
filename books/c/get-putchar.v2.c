#include <stdio.h>

// копирование входного потока в выходной

int main(){
    char c;
    
    while ( (c = getchar()) != EOF ){
        printf("%d\n", getchar() != EOF);
        putchar(c);
    }

    return 0;
}