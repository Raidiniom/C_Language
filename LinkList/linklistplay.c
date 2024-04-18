#include <stdio.h>
#include <stdlib.h>

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
    insertFront(&start, 60);

    displaylink(start);

    // Start inserting here!
    insertAt(&start, 5, 2);
    displaylink(start);

    delFront(&start);
    displaylink(start);

    delLast(&start);
    displaylink(start);
    
    delAt(&start, 3);
    displaylink(start);

    return 0;
}


// Function Definition
void insertRear(NodePtr *list, int data)
{
    NodePtr newData = (NodePtr)malloc(sizeof(Node));
    newData->data = data;
    newData->next = NULL;

    if (*list == NULL)
    {
        *list = newData;
        return;
    }
    
    NodePtr curr = *list;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = newData;
}

void insertFront(NodePtr *list, int data)
{
    NodePtr head = (NodePtr)malloc(sizeof(Node));

    if (head == NULL)
    {
        printf("No Memory Allocated");
    }

    head->data = data;
    head->next = *list;
    *list = head;
}

void insertAt(NodePtr *list, int data, int position)
{
    NodePtr head = (NodePtr)malloc(sizeof(Node));

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
    while (curr != NULL && postrk < position)
    {
        prev = curr;
        curr = curr->next;
        postrk++;
    }
    
    prev->next = curr->next;
    free(curr);
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