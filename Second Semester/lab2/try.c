#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *another; 
    struct node *prev;    
};


struct node* append(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->another = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}


void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


struct node* createList() {
    struct node* head = NULL;
    int data;
    printf("Введите элементы списка (0 для завершения): ");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;
        head = append(head, data);
    }
    return head;
}


void linkLists(struct node* head1, struct node* head2) {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        temp1->another = temp2;
        temp2->another = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL) {
        temp1->another = NULL;
        temp1 = temp1->next;
    }


    while (temp2 != NULL) {
        temp2->another = NULL;
        temp2 = temp2->next;
    }
}


void navigateList(struct node* head1, struct node* head2) {
    struct node* current = head1;
    char command;

    while (1) {
        if (current == NULL) {
            printf("Достигнут конец списка. Нажмите 'S' для возврата в начало.\n");
            scanf(" %c", &command);
            if (command == 'S' || command == 's') {
                current = head1;
            }
        }

        if (current != NULL) {
            printf("Текущее значение: %d\n", current->data);
            printf("Введите команду (W/A/S/D или 2/4/6/8): ");
            scanf(" %c", &command);

            switch (command) {
                case 'W': case 'w': case '2':
                    if (current->another != NULL) {
                        current = current->another;
                    } else {
                        printf("Нет связанного узла вверх.\n");
                    }
                    break;
                case 'A': case 'a': case '4':
                    if (current->prev != NULL) {
                        current = current->prev;
                    } else {
                        printf("Нет предыдущего узла.\n");
                    }
                    break;
                case 'S': case 's': case '8':
                    if (current->another != NULL) {
                        current = current->another;
                    } else {
                        printf("Нет связанного узла вниз.\n");
                    }
                    break;
                case 'D': case 'd': case '6':
                    if (current->next != NULL) {
                        current = current->next;
                    } else {
                        printf("Нет следующего узла.\n");
                    }
                    break;
                default:
                    printf("Неверная команда.\n");
            }
        }
    }
}

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
