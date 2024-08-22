#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} *Node;

Node create_Node();

bool insert_Front(Node *list, int data);
bool insert_Rear(Node *list, int data);
bool insert_At(Node *list, int data);

bool delete_Front(Node *list);
bool delete_Rear(Node *list);
bool delete_At(Node *list, int position);
bool delete_Item(Node *list, int item);

bool search_Link(Node list, int search_item);

void display_Link(Node list);

#endif