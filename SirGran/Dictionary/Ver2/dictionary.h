#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[16];

typedef struct {
    int prodID;
    String prodNAME;
    int prodQTY;
    float prodPRICE;
} Product;

typedef struct node {
    Product prod;
    struct node *next;
} NodeType, *NodePtr, *Stack;

typedef struct {
    NodePtr *data;
    int count;
    int max;
} ProdDict;

// Product
Product createProduct(int ID, String NAME, int QUANTITY, float PRICE) {
    Product start;

    start.prodID = ID;
    strcpy(start.prodNAME, NAME);
    start.prodQTY = QUANTITY;
    start.prodPRICE = PRICE;

    return start;
}

void displayProduct(Product prod) {
    printf("%d %.30s %d %.2f\n", prod.prodID, prod.prodNAME, prod.prodQTY, prod.prodPRICE);
}

// Stack
void initStack(Stack *start) {
    (*start) = NULL;
}

bool isStackEmpty(Stack stack) {
    return stack == NULL;
}

bool pushITEM(Stack *stack, Product item) {
    NodePtr newNODE = malloc(sizeof(NodeType));

    newNODE->prod = item;
    newNODE->next = (*stack);

    (*stack) = newNODE;

    return true;
}

bool popITEM(Stack *stack) {
    NodePtr deleteTHIS = (*stack);

    (*stack) = (*stack)->next;

    free(deleteTHIS);

    return true;
}

Product peekSTACK(Stack stack) {
    return (stack)->prod;
}

void displayStack(Stack stack) {
    while (stack != NULL)
    {
        displayProduct(stack->prod);

        stack = stack->next;
    }
}

// Dictionary
void initDictionary(ProdDict *dictionary, int max) {
    (*dictionary).count = 0;
    (*dictionary).max = max;

    (*dictionary).data = malloc(max * sizeof(NodePtr));

    for (int i = 0; i < max; i++)
    {
        (*dictionary).data[i] = NULL;
    }
    
}

int getHASH(ProdDict yourDictionary, Product prod) {
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        result += prod.prodNAME[i];
    }

    return (result + prod.prodID) % yourDictionary.max;
}

bool isDictionaryFull(ProdDict inventory) {
    return inventory.count >= (inventory.max * 0.7);
}

bool isDuplicate(ProdDict inventory, Product input) {
    for (int i = 0; i < inventory.max; i++)
    {
        while (inventory.data[i] != NULL)
        {
            if (inventory.data[i]->prod.prodID == input.prodID && strcmp(inventory.data[i]->prod.prodNAME, input.prodNAME) == 0)
            {
                return true;
            }
            
            
            inventory.data[i] = inventory.data[i]->next;
        }
        
    }

    return false;
}

bool transferITEM(ProdDict *inventory, Stack *hold) {
    int index = getHASH(*inventory, peekSTACK(*hold));
    if (!isDictionaryFull(*inventory))
    {
        while ((*inventory).data[index] != NULL)
        {
            if (isDuplicate(*inventory, peekSTACK(*hold)))
            {
                (*inventory).data[index]->prod.prodQTY += (*hold)->prod.prodQTY;
            }
            else
            {
                pushITEM(&(*inventory).data[index], peekSTACK(*hold));
            }
            
            (*inventory).count++;
            popITEM(hold);
            
        }
        
        return true;
    }
    else
    {
        printf("Inventory is Full!");
        return false;
    }
    
}


bool addITEM(ProdDict *inventory, Product prod) {
    // 
}

bool removeITEM(ProdDict *inventory, int id, String name) {
    // 
}

void displayDictionary(ProdDict inventory) {
    printf("Count: %d Max: %d\n", inventory.count, inventory.max);
    for (int i = 0; i < inventory.max; i++)
    {
        if (inventory.data[i] != NULL)
        {
            while (inventory.data[i] != NULL)
            {
                printf("%d - %.6d %.20s %.2d %.2f\n", i, inventory.data[i]->prod.prodID, inventory.data[i]->prod.prodNAME, inventory.data[i]->prod.prodQTY, inventory.data[i]->prod.prodPRICE);

                inventory.data[i] = inventory.data[i]->next;
            }
        }
        else
        {
            printf("%d - EMPTY\n", i);
        }
        
    }
    
}

// All for debugging and seeing stuff
void checkProdHash(ProdDict thisDicti, Stack thisStack) {
    while (thisStack != NULL)
    {
        printf("Hash number: %d\n", getHASH(thisDicti, thisStack->prod));
        
        thisStack = thisStack->next;
    }
    
}

#endif