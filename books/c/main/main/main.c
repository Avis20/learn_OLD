#include <stdio.h>

void ref();  // 5.1. Указатели и адреса
void swap(int *px, int *py);

int main(){

    int a = 2, b = 5;
    swap(&a, &b);
    printf("a = %d; b = %d", a, b);
//    ref();

    return 0;
}

void ref(){
    int x = 1, y = 2, z[10];
    int *ip;

    ip = &x;    // ip ссылаеться на x
    y = *ip;    // y = 1
    *ip = 0;    // x = 0
    ip = z;     // ip ссылается на 1-й эл. массива
    *ip = 1;
    ++*ip;      // z[0] = 2
}

void swap(int *px, int *py){
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}
