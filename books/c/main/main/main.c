#include <stdio.h>
#include <stdlib.h>
#include "chapter5.h"
#include "mygrep.h"
#include "myqsort.h"

///* Сортировка строк v2
int main(int argc, char *argv[]){

    int n;
    int numeric = 0; // флаг что числовая сортировка

    if (argc > 1 && strcmp(argv[1] == "-n") == 0){
        numeric = 1;
    }

    if ((n = read_lines(lineptr, MAXLINES)) >= 0 ){
        void *subname = ( int (*)(void *, void *) ) (numeric ? numcmp : strcmp2);
        qsort_lines2((void **)lineptr , 0, n-1, subname);
        write_lines(lineptr, n);
    }

    return 0;
}
//*/


/* mygrep - вывод строк, содержащий образец из последнего аргумента
int main (int argc, char *argv[]){

    if (0){ // debug

        int myargc = 1;
        char *myargv[] = {
            "program name",
//            "-n",
//            "hello,",
//            "world"
        };

        mygrep(myargc, myargv);

    } else {
        mygrep(argc, argv);
    }

    return 0;
}
*/

/* аналог echo; 2-я версия
int main(int argc, char *argv[]){

    if (1){ // debug

        int myargc = 3;
        char *myargv[] = {
            "program name", "hello,", "world"
        };

        for (int i = 1; i < myargc; i++){
            printf("%s%s", myargv[i], (i < myargc-1) ? " " : "" );
        }

    } else {

        while ( --argc > 0 ){
            printf("%s%s", *++argv, ( argc > 1 ) ? " " : "");
        }

    }
    printf("\n");
    return 0;
}
*/

/* аналог echo 1-я версия
int main(int argc, char *argv[]){

    for (int i = 1; i < argc; i++){
        printf("%s%s", argv[i], (i < argc-1) ? " " : "" );
    }
    printf("\n");

    return 0;
}
*/

/* вывод названия пути запуска
int main(int argc, char *argv[]){
    printf("%s; ", argv[0]);
    return 0;
}
*/

/* месяц по номеру
int main(){

    printf("%s\n", month_name(12));

    return 0;
}
*/

/* вычисление дат: пример многомерного массива
int main(){

    int year = 2019, month = 5, day = 1;
    int count_days = day_of_year(year, month, day);
    printf("%d\n", count_days);

    int res_month, res_day;
    month_day(1988, 61, &res_month, &res_day);
    printf("month = %d; day = %d", res_month, res_day);

    return 0;
}
*/

/* Сортировка строк
int main(){

    int count_lines;

    if ((count_lines = read_lines(lineptr, MAXLINES)) >= 0 ){
        // НЕ РАБОТАЕТ СОРТИРОВКА: ошибка сегментации
//        qsort_lines(lines, 0, count_lines-1);
        write_lines(lineptr, count_lines);
    }

    return 0;
}
*/
