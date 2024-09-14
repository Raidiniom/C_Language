#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node)); // allocate 3 nodes in the heap
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1; // setup first node
    head->next = second; // note: pointer assignment rule

    second->data = 2; // setup second node
    second->next = third;

    third->data = 3; // setup third link
    third->next = NULL;
// At this point, the linked list referenced by "head"
// matches the list in the drawing.
    return head;
}

void display(struct node *l)
{
    struct node *trav = l;
    while (trav != NULL)
    {
        printf("{%d} ", trav->data);
        trav = trav->next;  
    }
    
}

int length(struct node *l)
{
    int ctr = 0;
    while (l != NULL)
    {
        ctr++;
        l = l->next;
    }
    return ctr;
}

int main()
{
    struct node *theList = BuildOneTwoThree();

    display(theList);

    printf("\nThe length is %d", length(theList));

    return 0;
}