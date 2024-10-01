#ifndef STACKLINK_H
#define STACKLINK_H

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

Product createProd(int id, String name, int quantity, float price) {
    Product start;

    start.prodID = id;
    strcpy(start.prodNAME, name);
    start.prodQTY = quantity;
    start.prodPRICE = price;

    return start;
}

// Product
void displayProduct(Product prod) {
    printf("%d| %.10s| %d| %.2f %.10s", prod.prodID, prod.prodNAME, prod.prodQTY, prod.prodPRICE, "|");
}

// Stack
void initStack(Stack *s) {
    (*s) = NULL;
}

bool isEmpty(Stack s) {
    return s == NULL;
}

bool push(Stack *s, Product prod) {
    NodePtr newNODE = malloc(sizeof(NodeType));

    newNODE->prod = prod;
    newNODE->next = (*s);

    (*s) = newNODE;

    return true;
}

bool pop(Stack *s) {
    NodePtr deleteTHIS = (*s);

    (*s) = (*s)->next;

    free(deleteTHIS);

    return true;
}

Product peek(Stack s) {
    return s->prod;
}

void displayStack(Stack s) {
    while (s != NULL)
    {
        printf("%d| %.10s| %d| %.2f %.10s", s->prod.prodID, s->prod.prodNAME, s->prod.prodQTY, s->prod.prodPRICE, "|     ");
        s = s->next;
    }
    
}

// Dictionary
void initProdDict(ProdDict *dict, int max) {
    dict->count = 0;
    dict->max = max;

    dict->data = malloc(max * sizeof(NodeType));

    for (int i = 0; i < max; i++)
    {
        dict->data[i] = NULL;
    }
    
}

int getHash(ProdDict pd, Product prod) {
    int result = 0;

    result += prod.prodID;

    for (int i = 0; i < 5; i++)
    {
        result += prod.prodNAME[i];
    }
    

    return result % pd.max;
}

bool addITEM(ProdDict *pd, Product prod) {
    if (pd->count <= pd->max * 0.7)
    {
        push(&pd->data[getHash(*pd, prod)], prod);
        pd->count++;

        return true;
    }
    

    return false;
}

bool removeITEM(ProdDict *pd, int prodID, String prodNAME) {
    for (int i = 0; i < pd->max; i++) {
        NodePtr curr = pd->data[i];
        NodePtr prev = NULL;  // Track the previous node
        
        while (curr != NULL) {
            // Check if the current product matches the criteria
            if (curr->prod.prodID == prodID && strcmp(curr->prod.prodNAME, prodNAME) == 0) {
                // If it's the first node (top of the stack)
                if (prev == NULL) {
                    pd->data[i] = curr->next;  // Update the top of the stack
                } else {
                    prev->next = curr->next;  // Bypass the current node
                }
                
                free(curr);  // Free the memory
                pd->count--;  // Decrement the product count

                return true;  // Item successfully removed
            }
            
            // Move to the next node
            prev = curr;
            curr = curr->next;
        }
    }

    return false;  // Product not found
}


Product retrieveITEM(ProdDict pd, int prodID, String prodNAME) {
    for (int i = 0; i < pd.max; i++)
    {
        while (pd.data[i] != NULL)
        {
            if (pd.data[i]->prod.prodID == prodID && strcmp(pd.data[i]->prod.prodNAME, prodNAME))
            {
                return pd.data[i]->prod;
            }
            

            pd.data[i] = pd.data[i]->next;
        }
        
    }
    return createProd(404, "NULL", 0, 0);
}

void displayDictionary(ProdDict pd) {
    for (int i = 0; i < pd.max; i++)
    {
        printf("%d | %.5s", i, " ");
        displayStack(pd.data[i]);
        printf("\n");
    }
    
}

#endif