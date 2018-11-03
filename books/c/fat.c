#include <stdio.h>

// Вывод таблицы температур по Фаренгейту и Цельсию

int main (){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // нижняя граница температур
    upper = 300;    // верняя граница температур
    step = 20;      // величина шага

    while ( fahr <= upper ){
        celsius = (5.0/9.0) * (fahr - 32.0); // c = (5/9)(f - 32)
        printf("%3.0f %6.2f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}