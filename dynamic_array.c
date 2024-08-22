#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_array.h"

bool insert_Front(Node *list, int data) {
    Node new_node = malloc(sizeof(Node));

    if (list != NULL)
    {
        new_node->data = data;
        new_node->next = *list;

        *list = new_node;
        return true;
    }

    return false;
    
}

bool insert_Rear(Node *list, int data) {
    Node new_node = malloc(sizeof(Node));

    if (list != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;

        Node trav = *list;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        
        trav->next = new_node;
    
        return true;
    }
    
    return false;
}

bool insert_At(Node *list, int data, int position) {
    Node new_node = malloc(sizeof(Node));

    if (list != NULL)
    {
        new_node->data = data;

        Node trav = *list;
        for (int i = 0; trav != NULL && i < position; i++)
        {
            trav = trav->next;
        }

        new_node->next = trav->next;
        trav->next = new_node;

        return true;
        
    }

    return false;
    
}

bool delete_Front(Node *list) {
    if (list != NULL)
    {
        Node temp = (*list)->next;
        free(*list);

        *list = temp;
    }
    
}

bool delete_Rear(Node *list) {
    // 
}

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
}