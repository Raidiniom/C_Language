#include <stdio.h>
#include <stdlib.h>

typedef struct gNode
{
    int data;
    struct gNode *next;
} Node, *NodePtr;

// Header Functions
void add(NodePtr *list, int data);
void display(NodePtr list);

// Main 
int main()
{
    NodePtr myList = NULL;

    return 0;
}

// Function Declaration
void add(NodePtr *list, int data)
{
    NodePtr newNode = malloc(sizeof(Node));

    // Tells me if memory allocation failed
    if (newNode == NULL)
    {
        printf("WHAT HAPPENED WTF!!!");
        return;
    }
    
}
void display(NodePtr list)
{
    // 
}