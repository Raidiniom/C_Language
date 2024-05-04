#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *NodePtr;

// Functions
void insertRear(NodePtr *list, int data);
void insertFront(NodePtr *list, int data);
void insertAt(NodePtr *list, int data, int position);
void delFront(NodePtr *list);
void delLast(NodePtr *list);
void delAt(NodePtr *list, int position);
void delItem(NodePtr *list, int deldat);
int search(NodePtr list, int data);
void displaylink(NodePtr list);

// Main
int main()
{
    NodePtr start = NULL;

    insertRear(&start, 10);
    insertRear(&start, 20);
    insertRear(&start, 30);
    insertRear(&start, 40);
    insertRear(&start, 50);
    displaylink(start);

    // Inserting
    insertAt(&start, 5, 2);
    printf("\nInsert At: ");
    displaylink(start);

    insertFront(&start, 60);
    printf("\nInsert Front: ");
    displaylink(start);

    // Deleting
    delFront(&start);
    printf("\nDelete Front: ");
    displaylink(start);

    delLast(&start);
    printf("\nDelete Last: ");
    displaylink(start);
    
    delAt(&start, 3);
    printf("\nDelete At: ");
    displaylink(start);

    // Searching
    (search(start, 30) > 0) ? printf("It exist"): printf("It does not exist");

    return 0;
}


// Function Definition
void insertRear(NodePtr *list, int data)
{
    NodePtr newData = malloc(sizeof(Node));
    newData->data = data;
    newData->next = NULL;

    // If the list is initialy empty
    if (*list == NULL)
    {
        *list = newData;
        return;
    }
    
    // Traverses to the last of the link list
    NodePtr curr = *list;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = newData;
}

void insertFront(NodePtr *list, int data)
{
    NodePtr head =  malloc(sizeof(Node));

    // If malloc failed
    if (head == NULL)
    {
        printf("No Memory Allocated");
    }

    // inserts the data to the head
    head->data = data;
    // uses the NULL of the head at the back
    head->next = *list;
    // the list from the main will be pointing to the new link list
    *list = head;
}

void insertAt(NodePtr *list, int data, int position)
{
    NodePtr head =  malloc(sizeof(Node));

    head->data = data;
    head->next = NULL;

    NodePtr curr = *list;
    int postrk = 1;
    while (curr != NULL && postrk < position)
    {
        curr = curr->next;
        postrk++;
    }

    head->next = curr->next;
    curr->next = head;
    
}

void delFront(NodePtr *list)
{
    NodePtr head = *list;

    *list = head->next;

    free(head);
}

void delLast(NodePtr *list)
{
    NodePtr head = *list;
    NodePtr last;

    while (head->next->next != NULL)
    {
        head = head->next;
    }
    last = head->next;
    head->next = NULL;

    free(last);
}

void delAt(NodePtr *list, int position)
{
    NodePtr curr = *list;
    NodePtr prev;

    int postrk = 1;
    while (curr != NULL && postrk < position - 1)
    {
        prev = curr;
        curr = curr->next;
        postrk++;
    }
    
    prev->next = curr->next;
    free(curr);
}

int search(NodePtr list, int data)
{
    while (list->next != NULL)
    {
        if (list->data == data)
        {
            return 1;
        }
        list = list->next;
    }
    return -1;
}

void displaylink(NodePtr list)
{
    NodePtr disply = list;

    printf("(");
    while (disply != NULL)
    {
        printf("%d", disply->data);
        disply = disply->next;
        if(disply != NULL)
        {
            printf(", ");
        }
    }
    printf(")\n");
}