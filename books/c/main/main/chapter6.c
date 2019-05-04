
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chapter6.h"
#define min(a, b) ( (a) < (b) ? (a) : (b) )
#define max(a, b) ( (a) > (b) ? (a) : (b) )
#define MAXWORD 100

// Массив структур
struct key keytable[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0
};
int NKEYS = sizeof keytable / sizeof keytable[0];

// Создает структуру point из x и y
struct point make_point(int x, int y){
    struct point tmp;

    tmp.x = x;
    tmp.y = y;
    return tmp;
}

// Сложение координат двух точек
struct point add_point( struct point pt1, struct point pt2 ){
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}

// вывод точки
void print_point(struct point pt){
    printf("x = %d; y = %d\n", pt.x, pt.y);
}

// Находиться ли точка внутри прямоугольника
int is_in_rect (struct rect r, struct point p){
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

// Канонический прямоугольник
struct rect canon_rect(struct rect r){
    struct rect tmp;

    tmp.pt1.x = min( r.pt1.x, r.pt2.x );
    tmp.pt1.y = min( r.pt1.y, r.pt2.x );
    tmp.pt2.x = max( r.pt1.x, r.pt2.x );
    tmp.pt2.y = max( r.pt1.y, r.pt2.y );
    return tmp;
}

void count_c_words(){
    int n;
    char word[MAXWORD];

    while ( getword(word, MAXWORD) != EOF ){
        if ( isalpha(word[0]) ){
            if ( ( n = binsearch(word, keytable, NKEYS) ) >= 0 ){
                keytable[n].count++;
            }
        }
    }

    for (n = 0; n < NKEYS; n++){
        if ( keytable[n].count > 0 ){
            printf("%4d %s\n", keytable[n].count, keytable[n].word);
        }
    }
}

int getword(char *word, int lim){
    int c;
    char *w = word;

    while ( isspace( c = getchar() ) );

    if ( c != EOF ) *w++ = c;
    *w = '\0';
    return word[0];
}

int binsearch( char *word, struct key tab[], int n ){
    int cond;
    int low, high, middle;

    low = 0;
    high = n - 1;
    while ( low <= high ){
        middle = (low+high)/2;
        if ( ( cond = strcmp(word, tab[middle].word) ) < 0 ){
            high = middle - 1;
        } else if ( cond > 0 ){
             low = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}


























