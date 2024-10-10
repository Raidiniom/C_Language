#ifndef STACKTODICTIONARY_H
#define STACKTODICTIONARY_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[16];

typedef struct {
    int id;
    String name;
    int quantity;
    float price;
} Product;

typedef struct node
{
    Product item;
    struct node *next;
} NodeType, *NodePtr, *Stack; // Stack

typedef struct {
    NodePtr *data;
    int count;
    int max;
} Dictionary; // Dictionary, in this context this is the inventory

// Product part
Product create_product(int id, String name, int quantity, float price) {
    // create product helper function
    Product init_start;

    init_start.id = id;
    strcpy(init_start.name, name);
    init_start.quantity = quantity;
    init_start.price = price;

    return init_start;
}

void display_product(Product item) {
    // display the product that is being passed in here
    printf("%d | %.20s | %d | %.2f \n", item.id, item.name, item.quantity, item.price);
}

// Stack part
void init_stack(Stack *stack) {
    // initialize the stack or start the stack itself
    *stack = NULL;
}

bool isStackEmpty(Stack stack) {
    // checks if the stack is empty or has data in it
    return stack == NULL;
}

Product peek_item(Stack stack) {
    return stack->item;
}

void push_item(Stack *stack, Product item) {
    // inserts the item into the stack
    Stack insert_item = (NodePtr) malloc(sizeof(NodeType));

    insert_item->item = item;
    insert_item->next = (*stack);

    (*stack) = insert_item;
}

void pop_item(Stack *stack) {
    // pops out the item at the head of the link list or the first item of the stack
    NodePtr delete_item = NULL;

    delete_item = (*stack);

    (*stack) = (*stack)->next;

    free(delete_item);
}

void display_stack(Stack stack) {
    // displays the items within the stack
    if (!isStackEmpty(stack))
    {
        while (stack != NULL)
        {
            display_product(stack->item);

            stack = stack->next;
        }
        
    }
    else
    {
        printf("This stack is Empty!");
    }
    
}

/*Dictionary Part

Note: should drain the stack where the items are being held
*/
void init_dictionary(Dictionary *dictionary, int max) {
    // initialize or starts the dictionary
    (*dictionary).count = 0;
    (*dictionary).max = max;
    (*dictionary).data = (NodePtr*) malloc(max * sizeof(NodePtr));

    for (int i = 0; i < max; i++)
    {
        (*dictionary).data[i] = NULL;
    }
    
}

int get_hash(Product item) {
    // getting the hash value is by getting the first 3 chars of the name plus the id of the item
    int hash = 0;

    for (int i = 0; i < 3; i++)
    {
        hash += item.name[i];
    }
    
    return hash += item.id;
}

bool is_item_dupicate(Dictionary dictionary, int id, String name) {
    // Checks in the dictionary if it has the same item
    int hash_index = get_hash(create_product(id, name, 0, 0)) % dictionary.max;

    if (!isStackEmpty(dictionary.data[hash_index]))
    {
        NodePtr trav = dictionary.data[hash_index];

        while (trav != NULL)
        {
            if (trav->item.id == id && strcmp(trav->item.name, name) == 0)
            {
                return true;
            }
            
            trav = trav->next;
        }
        
    }
    
    return false;
}

void add_item(Dictionary *dictionary, Stack *stack) {
    // adding the items into the dictionary

    NodePtr item_add = (NodePtr) malloc(sizeof(NodeType));

    int hash_index = get_hash((*stack)->item) % dictionary->max;

    item_add->item = peek_item(*stack);

    // checks if it is empty or not
    if (isStackEmpty((*dictionary).data[hash_index]))
    {
        item_add->next = dictionary->data[hash_index];
        dictionary->data[hash_index] = item_add;
    }
    else if (is_item_dupicate(*dictionary, peek_item(*stack).id, peek_item(*stack).name))
    {
        NodePtr trav = dictionary->data[hash_index];
        while (trav != NULL)
        {
            if (trav->item.id == (*stack)->item.id && strcmp(trav->item.name, (*stack)->item.name) == 0)
            {
                trav->item.quantity += peek_item(*stack).quantity;
                break;
            }
            
            trav = trav->next;
        }
        
    }
    else if (!is_item_dupicate(*dictionary, peek_item(*stack).id, peek_item(*stack).name))
    {
        item_add->next = dictionary->data[hash_index];
        dictionary->data[hash_index] = item_add;
    }

    pop_item(stack);

    (*dictionary).count++;
}

void remove_item(Dictionary *dictionary, int id, String name) {
    // remove the specific item being inputted
    Product find = create_product(id, name, 0, 0);

    int hash_index = get_hash(find) % dictionary->max;

    NodePtr curr = dictionary->data[hash_index];
    NodePtr prev = NULL;

    while (curr != NULL)
    {
        if (curr->item.id == id && strcmp(curr->item.name, name)  == 0)
        {
            if (prev ==  NULL)
            {
                dictionary->data[hash_index] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            
            free(curr);

            dictionary->count--;
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
}

void display_dictionary(Dictionary dictionary) {
    for (int i = 0; i < dictionary.max; i++)
    {
        if (dictionary.data[i] != NULL)
        {
            NodePtr trav = dictionary.data[i];
            printf("%d | ", i);
            while (trav != NULL)
            {
                printf("%d - %.10s - %d - %.2f | ", trav->item.id, trav->item.name, trav->item.quantity, trav->item.price);

                trav = trav->next;
            }
            printf("\n");
        }
        else
        {
            printf("%d | Empty\n", i);
        }
    }
}


// debugging functions
void debug_dictionary(Dictionary dictionary) {
    // checking if the init_dictionary works
    printf("\nDebugging\n");
    for (int i = 0; i < dictionary.max; i++)
    {
        (dictionary.data[i] == NULL) ? printf("%d | Empty here!\n", i) : printf("%d | Item here!\n");
    }
    
}

void debug_get_hash(Stack stack) {
    while (stack != NULL)
    {
        printf("%d\n", get_hash(stack->item) % 20);

        stack = stack->next;
    }
    
}

/*
TEST TEST TEST TEST 
*/

#endif