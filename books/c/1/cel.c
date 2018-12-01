#include <stdio.h>

// Вывод таблицы температур Цельсию по Фаренгейту

int main (){
    float fahr, celsius = 0;
    int lower, upper, step;

    lower = 0;      // нижняя граница температур
    upper = 100;    // верняя граница температур
    step = 20;      // величина шага

    while ( celsius <= upper ){
        fahr = (celsius * (9.0/5.0)) + 32;
        printf("%3.0f %6.2f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}