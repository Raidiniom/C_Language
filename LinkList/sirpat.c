#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void addLast(Node **head, int num);
bool search(Node *head, int sernum);
void delete(Node **head, int delnum);
void display(Node *head);

int main()
{
    Node *head = NULL;
    // Node *node1 = (Node*)malloc(sizeof(Node));

    // node1->data = 1;
    // node1->next = NULL;

    // head = node1;

    for (int i = 0; i < 8; i++)
    {
        addLast(&head, i);
    }
    
    display(head);
    (search(head, 6)) ? printf("\nThere you are!") : printf("\nWhere you are?");
    delete(&head, 5);
    printf("\n");
    display(head);

    return 0;
}

void addLast(Node **head, int num)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = num;
    newNode->next = NULL;

    while (*head != NULL)
    {
        head = &(*head)->next;
    }
    
    *head = newNode;

    // Another Implementation
    // Node *trav;
    // trav = *head;

    // while (trav->next != NULL)
    // {
    //     trav = trav->next;
    // }
    
    // trav->next = newNode;
}

bool search(Node *head, int sernum)
{
    Node *trav = head;

    while (trav != NULL)
    {
        if (sernum == trav->data)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

void delete(Node **head, int delnum)
{
    Node *temp = *head;
    Node *prev;

    while (temp->next != NULL && temp->next->data == delnum)
    {
        prev = temp;
        temp = temp->next;
    }
    
    
    free(temp);
}

void display(Node *head)
{
    Node *trav = head;

    printf("{");
    while (trav != NULL)
    {
        printf("%d", trav->data);
        trav = trav->next;

        if (trav != NULL)
        {
            printf(", ");
        }
    }
    printf("}");
}