#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *vert;
    struct Node *prev;
};

typedef struct Node node;

node *append(node* head, int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->vert = NULL;
    newnode->prev = NULL;

    if(head == NULL){
        return newnode;
    }
    node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->prev = last;
    return head;
}

void printTable(node* head){
    node* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node *createNode(){
    node *head = NULL;
    int data;
    printf("Список(0 для завершения ввода): ");
    while (1)
    {
        scanf("%d", &data);
        if(data == 0)
            break;
        head = append(head, data);
    }
    return head;    
}

void link(node* head1, node* head2){
    node *cur1 = head1;
    node *cur2 = head2;

    while (cur1 && cur2)
    {
        cur1->vert = cur2;
        cur2->vert = cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    while (cur1)
    {
        cur1->vert = NULL;
        cur1 = cur1->next;
    }

    while (cur2)
    {
        cur2->vert = NULL;
        cur2 = cur2->next;
    }
}

void navigate(node *head1, node *head2){
    node* current = head1;
    char vector;

    while (1)
    {
        if(current == NULL){
            printf("Вы достигли границы списка!\n");
            scanf(" %c", &vector);
        }
        if(current){
            printf("Ваша позиция: %d\n", current->data);
            printf("Используйте WASD или Numpad для перемещения.\n");
            scanf(" %c", &vector);
            switch (vector)
            {
            case 'W': case 'w': case '8':
                if(current->vert){
                    current = current->vert;
                } else {
                    printf("Невозможно выполнить команду.\n");
                }
                break;
            
            case 'A': case 'a': case '4':
                if(current->prev){
                    current = current->prev;
                } else {
                    printf("Невозможно выполнить команду.\n");
                }
                break;
            case 'S': case 's': case '2':
                if(current->vert){
                    current = current->vert;
                } else {
                    printf("Невозможно выполнить команду.\n");
                }
                break;
            
            case 'D': case 'd': case '6':
                if(current->next){
                    current = current->next;
                } else {
                    printf("Невозможно выполнить команду.\n");
                }
                break;
            default:
                printf("Неверная команда.\n");
                break;
            }
        }
    }
    
}

int main(){
    printf("Первый ");
    node *list1 = createNode();
    printf("Второй ");
    node *list2 = createNode();
    printTable(list1);
    printTable(list2);

    navigate(list1, list2);

}