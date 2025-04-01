#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *another; 
    struct node *prev;    
};

struct node* append(struct node* head, int data);
void printList(struct node* head);
struct node* createList();
void linkLists(struct node* head1, struct node* head2);
void navigateList(struct node* head1, struct node* head2);

#endif