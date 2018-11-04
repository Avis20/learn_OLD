#include <stdio.h>

// подсчет кол-ва пробелов, знаков табуляции и символов конца строки

int main(){

    long count_spaces = 0, count_tabs = 0, count_endstr = 0;
    char c;

    while ( (c = getchar()) != EOF )
        if ( c == ' ' ){
            ++count_spaces;
        } else if ( c == '\t' ){
            ++count_tabs;
        } else if ( c == '\0' ){
            ++count_endstr;
        }

    printf("Кол-во пробелов = %ld; Кол-во табуляций = %ld; Кол-во символов конца строки = %ld\n", count_spaces, count_tabs, count_endstr);

    return 0;
}