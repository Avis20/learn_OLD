#include <stdlib.h>
#include "chapter5.h"
#include "chapter1.h"

// копирует сторку s в t, 1-я версия с индексированием массива
void strcpy1( char *s, char *t ){
    for (int i = 0; (s[i] = t[i]) != '\0'; i++);
}

// копирует сторку s в t, 2-я версия с указателями
void strcpy2( char *s, char *t ){
    for (; (*s = *t) != '\0'; s++, t++);
}

// копирует сторку s в t, 3-я версия с указателями
void strcpy3( char *s, char *t ){
    while (*s++ = *t++);
}

// возвращает отрицательное число если s < t, 0 при s = t, положительное при s > t; версия 1
int strcmp1(char *s, char *t){
    int i;
    for (i = 0; s[i] == t[i]; i++ ){
        if ( s[i] == '\0'){
            return 0;
        }
    }

    return s[i] - t[i];
}

// возвращает отрицательное число если s < t, 0 при s = t, положительное при s > t; версия 2
int strcmp2(char *s, char *t){
    for (; *s == *t; s++, t++){
        if ( *s == '\0' ){
            return 0;
        }
    }

    return *s - *t;
}

// присоединяет строку t к концу s; версия 1
void strcat1(char *s, char *t){
    int i, j;
    i = j = 0;

    while (s[i] != '\0'){
        i++;
    }

    while ( ( s[i++] = t[j++] ) != '\0' );
}

// 5.3; присоединяет строку t к концу s; версия 2
void strcat2(char *s, char *t){
    while (*(++s) != '\0');
    while (*s++ = *t++);
}

// 5.4; возвращает 1, если строка t присутствует в конце строки s, 0 в противном случае
int strend(char *s, char *t){

}

#define ALLOCSIZE 1000

static char alloc_buf[ALLOCSIZE];
static char *alloc_cp = alloc_buf;

char *alloc(int n){
    if ( alloc_buf + ALLOCSIZE - alloc_cp >= n ){
        alloc_cp += n;
        return alloc_cp - n;
    } else {
        return 0;
    }
}

void afree( char *p ){
    if ( p >= alloc_buf && p < alloc_buf + ALLOCSIZE ){
        alloc_cp = p;
    }
}

#define MAXLINES 100
#define MAXLEN 100

char *lines[MAXLINES];

int read_lines( char *lines[], int max_lines ){
    int len, nlines;

    char *p, line[MAXLEN];
    nlines = 0;

    while ( (len = get_line(line, MAXLEN)) > 0 ){
        if ( nlines >= max_lines || ( p = alloc(len) ) == NULL ){
            return -1;
        } else {
            line[len-1] = '\0'; // у каждой введенной строки удаляем последний символ конца строки
            strcpy3(p, line);
            lines[nlines++] = p;
        }
    }
    return nlines;
}

int write_lines( char *lines[], int nlines ){
    for (int i = 0; i < nlines; i++){
        printf("%s\n", lines[i]);
    }
}

// сортировка в порядке возрастания
void qsort_lines(char *lines[], int left, int right ){
    int i, last;

    if ( left >= right ){ // ничего не делать если в массиве меньше двух эл.
        return;
    }
    int middle = (left+right) / 2;
    swap( lines, left, middle );
    last = left;
    for (i = left+1; i <= right; i++){
        if ( strcmp2(lines[i], lines[left]) < 0 ){
            swap(lines, ++last, i);
        }
    }
    swap(lines, left, last);
    qsort_lines(lines, left, last-1);
    qsort_lines(lines, last+1, right);
}

void swap(char *lines, int i, int j){
    char *tmp;

    tmp = lines[i];
    lines[i] = lines[j];
    lines[j] = tmp;
}


//################################################
// вычисление дня года по месяцу и дню
int day_of_year( int year, int month, int day ){
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for ( i = 1; i < month; i++ ){
        day += daytab[leap][i];
    }
    return day;
}

// вычисление месяца и даты по дню в году
void month_day(int year, int year_of_day, int *pmonth, int *pday){
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; year_of_day > daytab[leap][i]; i++){
        year_of_day -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = year_of_day;
}

char *month_name(int n){
    return ( n < 1 || n > 12 ) ? month_names[0] : month_names[n];
}












