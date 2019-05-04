#include "chapter6.h"
#define min(a, b) ( (a) < (b) ? (a) : (b) )
#define max(a, b) ( (a) > (b) ? (a) : (b) )

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

struct rect canon_rect(struct rect r){
    struct rect tmp;

    tmp.pt1.x = min( r.pt1.x, r.pt2.x );
    tmp.pt1.y = min( r.pt1.y, r.pt2.x );
    tmp.pt2.x = max( r.pt1.x, r.pt2.x );
    tmp.pt2.y = max( r.pt1.y, r.pt2.y );
    return tmp;
}































