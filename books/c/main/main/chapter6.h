#ifndef CHAPTER6_H
#define CHAPTER6_H

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point make_point(int x, int y);
struct point add_point( struct point pt1, struct point pt2 );
void print_point(struct point pt);
int is_in_rect (struct rect r, struct point p);
struct rect canon_rect(struct rect r);

#endif // CHAPTER6_H

