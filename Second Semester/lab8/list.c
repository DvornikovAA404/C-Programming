#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *down;
};

struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = 0;
    n->down = 0;
    return n;
}

void appendNode(struct Node** h, int x) {
    struct Node* n = createNode(x);
    if (!*h) {
        *h = n;
        return;
    }
    struct Node* t = *h;
    while (t->next) t = t->next;
    t->next = n;
}

void linkLists(struct Node* u, struct Node* d) {
    while (u && d) {
        u->down = d;
        u = u->next;
        d = d->next;
    }
}
