#include <stdio.h>
#include <stdlib.h>

typedef struct gNode
{
    int data;
    struct gNode *next;
} Node, *NodePtr;

// Header Functions
void add(NodePtr *list, int data);
void addRear(NodePtr *list, int data);
void insert(NodePtr *list, int data, int pos);
void swapfront(NodePtr *list);
void swaprear(NodePtr *list);
void swapPos(NodePtr *list, int pos1, int pos2);
void display(NodePtr list);

// Main 
int main()
{
    NodePtr myList = NULL;

    for (int i = 0; i < 6; i++)
    {
        addRear(&myList, (i + 1));
    }
    
    printf("Initial List: ");
    display(myList);

    swapPos(&myList, 2, 5);

    printf("Swapped Data Position: ");
    display(myList);

    swapfront(&myList);

    printf("Swapped Front: ");
    display(myList);

    swaprear(&myList);

    printf("Swapped Rear: ");
    display(myList);

    insert(&myList, 10, 5);

    printf("Insert: ");
    display(myList);

    return 0;
}

// Function Declaration
void add(NodePtr *list, int data) // This is add/insert front
{
    NodePtr newNode = malloc(sizeof(Node));

    // Tells me if memory allocation failed
    if (newNode == NULL)
    {
        printf("WHAT HAPPENED WTF!!!");
        return;
    }
    
    // takes and inserts the data intp the new node
    newNode->data = data;
    // the new node's pointer next will point to the initial NULL of the list from main before we populated the list
    newNode->next = *list;

    // the list will now point the new node being made in heap
    *list = newNode;
}

void addRear(NodePtr *list, int data)
{
    NodePtr newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    // if the list is initially empty
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    // will traverse until NULL
    NodePtr trav = *list;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    
    trav->next = newNode;
    
}

void insert(NodePtr *list, int data, int pos)
{
    NodePtr newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    int trkpos = 0;
    NodePtr trav = *list;
    while (trav != NULL && trkpos < pos - 1)
    {
        trkpos++;
        trav = trav->next;
    }
    
    newNode->next = trav->next;
    trav->next = newNode;
    
}

void swapfront(NodePtr *list)
{
    NodePtr prev = NULL, curr = *list;

    prev = curr;
    curr = curr->next;
    prev->next = curr->next;
    curr->next = prev;
    *list = curr;
}

void swaprear(NodePtr *list)
{
    NodePtr prev = NULL, curr = *list;

    while (curr->next->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next = curr->next->next;
    prev->next->next = curr;
}

void swapPos(NodePtr *list, int pos1, int pos2)
{
    int ctr1 = 1, ctr2 = 1;
    NodePtr prev1 = NULL, prev2 = NULL, trav1 = *list, trav2 = *list;

    // find position no.1
    while (trav1 != NULL && ctr1 < pos1)
    {
        prev1 = trav1;
        trav1 = trav1->next;
        ctr1++;
    }
    
    // find position no.2
    while (trav2 != NULL && ctr2 < pos2)
    {
        prev2 = trav2;
        trav2 = trav2->next;
        ctr2++;
    }
    
    // check if both nodes are adjacent or beside each other
    if (pos1 == pos2 - 1)
    {
        prev1->next = trav2;
        trav1->next = trav2->next;
        trav2->next = trav1;
    }
    else
    {
        prev1->next = trav2;
        prev2->next = trav1;

        NodePtr temp = trav1->next;
        trav1->next = trav2->next;
        trav2->next = temp;
    }
    
}

void display(NodePtr list)
{
    // traverse points to the list from main
    NodePtr trav = list;
    printf("{");
    // checks of traverse is null or not
    while (trav != NULL)
    {
        printf("%d", trav->data);
        // checks if the next of the trav is null or not
        if(trav->next != NULL)
        {
            printf(", ");
        }
        // makes trav into the next node
        trav = trav->next;
    }
    printf("}\n");
}