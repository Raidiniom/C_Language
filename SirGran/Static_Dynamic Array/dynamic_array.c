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
        for (int i = 1; trav != NULL && i < position; i++)
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

        return true;
    }
    
    return false;
}

bool delete_Rear(Node *list) {
    if (list != NULL)
    {
        Node trav = *list;
        while (trav->next->next != NULL)
        {
            trav = trav->next;
        }
        
        free(trav->next);
        trav->next = NULL;

        return true;
    }
    
    return false;
}

bool delete_At(Node *list, int position) {
    if (list != NULL)
    {
        Node trav = *list;
        Node prev;
        for (int i = 1; trav != NULL && i < position; i++)
        {
            prev = trav;
            trav = trav->next;
        }

        prev->next = trav->next;
        free(trav);
        
        return true;
    }

    return false;    
}

bool delete_Item(Node *list, int item) {
    if (list != NULL)
    {
        
        Node trav = *list;
        Node prev;
        for (;trav != NULL && trav->data != item ;)
        {
            prev = trav;
            trav = trav->next;
        }

        prev->next = trav->next;
        free(trav);

        return true;        
    }
    
    return false;
}

void search_Item(Node list, int search_item) {
    bool found = false;
    if (list != NULL)
    {
        while (list != NULL && list->data != search_item)
        {   
            if (list->data == search_item)
            {
                found = true;
                break;
            }
        
            list = list->next;
        }

        if (found)
        {
            printf("Found Item: %d\n", list->data);
        }
        else
        {
            printf("Item not Found");
        }
    }
    
}

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
    
    printf("]\n");
}