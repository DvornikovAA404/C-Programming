#include "task.h"



int main() {
    struct node* list1 = createList();
    printf("Первый список: ");
    printList(list1);

    struct node* list2 = createList();
    printf("Второй список: ");
    printList(list2);

    linkLists(list1, list2);

    navigateList(list1, list2);

    return 0;
}