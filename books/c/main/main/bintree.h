#ifndef BINTREE_H
#define BINTREE_H

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *add_tree(struct tnode *, char *);
void print_tree(struct tnode *);
struct tnode *talloc();
char *strdup2(char *);

#endif // BINTREE_H

