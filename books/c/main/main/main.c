#include <stdio.h>

void swap1(int a, int b);
void swap2(int *px, int *py);

int main(){

    int a = 1, b = 2;
    swap1(a, b);
    printf("a = %d; b = %d\n", a, b);

    swap2(&a, &b);
    printf("a = %d; b = %d\n", a, b);
    return 0;
}

void swap1(int a, int b){
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *px, int *py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
