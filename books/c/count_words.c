#include <stdio.h>
#define IN 1
#define OUT 0

// подсчет строк, слов, и символов во входном потоке

int main(){

    int count_lines, count_words, count_chars, state;
    char c;

    state = OUT;
    count_lines = count_words = count_chars = 0;

    while ( (c = getchar()) != EOF ){
        ++count_chars;
        if ( c == '\n' ) ++count_lines;
        if ( c == ' ' || c == '\n' || c == '\t' ){
            state = OUT;
        } else if ( state == OUT ){
            state = IN;
            ++count_words;
        }
    }

    printf("%d %d %d\n", count_lines, count_words, count_chars);

    return 0;
}