#include <stdio.h>

int main(){

    int is_last_char_space = 0;
    char c;
    while ( (c = getchar()) != EOF ){
        if ( c == ' ' ){
            if ( !is_last_char_space ) putchar(' ');
            is_last_char_space = 1;
        } else {
            putchar(c);
            is_last_char_space = 0;
        }
    }

    return 0;
}