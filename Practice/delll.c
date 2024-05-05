#include <stdio.h>
#include <stdlib.h>

typedef struct gdata
{
    int data;
    struct gdata *next;
} Node, *NodeP;

void insertRear(NodeP *list, int data);
void insertFront(NodeP *list, int data);
void delfront(NodeP *list);
void delrear(NodeP *list);
void delat(NodeP *list, int pos);
void delall(NodeP *list, int deldat);
void display(NodeP list);

int main()
{
    NodeP myList = NULL;

    insertRear(&myList, 4);
    for (int i = 0; i < 7; i++)
    {
        insertRear(&myList, (i + 1));
    }
    insertRear(&myList, 4);
    
    printf("Initail List: ");
    display(myList);

    // delfront(&myList);
    // delrear(&myList);
    // delat(&myList, 2);
    delall(&myList, 4);

    printf("Deletes: ");
    display(myList);

    return 0;
}

void insertRear(NodeP *list, int data)
{
    NodeP newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    
    NodeP trav = *list;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    
    trav->next = newNode;
}

void insertFront(NodeP *list, int data)
{
    NodeP newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = *list;

    *list = newNode;
    
}

void delfront(NodeP *list)
{
    NodeP hold = *list;

    *list = hold->next;

    free(hold);
}

void delrear(NodeP *list)
{
    NodeP hold = *list, temp;

    while (hold->next->next != NULL)
    {
        hold = hold->next;
    }

    temp = hold->next;
    hold->next = NULL;
    free(temp);
}

void delat(NodeP *list, int pos)
{
    NodeP hold = *list, temp;
    int trkpos = 1;

    while (hold != NULL && trkpos < pos - 1)
    {
        trkpos++;
        hold = hold->next;
    }

    temp = hold->next;
    hold->next = hold->next->next;

    free(temp);
}

void delall(NodeP *list, int deldat)
{
    NodeP curr = *list;
    NodeP temp;

    // Handle the case of deleting nodes at the beginning of the list
    while (curr != NULL && curr->data == deldat)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    // Update the list pointer if necessary
    *list = curr;

    // Iterate through the rest of the list
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == deldat)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
}



void display(NodeP list)
{
    NodeP trav = list;
    printf("{");
    while (trav != NULL)
    {
        printf("%d", trav->data);
        if (trav->next != NULL)
        {
            printf(", ");
        }
        trav = trav->next;
    }
    
    printf("}\n");
}