#include <stdio.h>
#include <stdlib.h>
#include "chapter5.h"

int main(){

    printf("%s\n", month_name(12));

    return 0;
}

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
char *lines[MAXLINES];
int main(){

    int count_lines;

    if ((count_lines = read_lines(lines, MAXLINES)) >= 0 ){
        // НЕ РАБОТАЕТ СОРТИРОВКА: ошибка сегментации
//        qsort_lines(lines, 0, count_lines-1);
        write_lines(lines, count_lines);
    }

    return 0;
}
*/
