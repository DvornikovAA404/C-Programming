#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    struct Node *next;
    struct Node *down;
};

struct Node* createNode(int data);
void appendNode(struct Node** head, int data);
struct Node* createList(); // только для completeness, но в тестах не используем из-за scanf
void printList(struct Node* head); // тоже не тестируем напрямую
void linkLists(struct Node* upper, struct Node* lower);
void navigate(struct Node* start); // интерактивная, не тестируем

#endif
