#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_array.h"

Node create_Node() {
    Node start_node = malloc(sizeof(Node));

    if (start_node != NULL)
    {
        start_node->next = NULL;
    }
    

    return start_node;
};

bool insert_Front(Node *list, int data) {
    Node new_node = create_Node();

    if (list != NULL)
    {
        new_node->data = data;
        new_node->next = *list;

        *list = new_node;
        return true;
    }

    return false;
    
}

bool insert_Rear(Node *list, int data);
bool insert_At(Node *list, int data);

bool delete_Front(Node *list);
bool delete_Rear(Node *list);
bool delete_At(Node *list, int position);
bool delete_Item(Node *list, int item);

bool search_Link(Node list, int search_item);

void display_Link(Node list) {
    printf("[");
    while (list != NULL)
    {
        printf("%d", list->data);
        list = list->next;

        if (list != NULL)
        {
            printf(", ");
        }
        
    }
    
    printf("]\n\n");
};