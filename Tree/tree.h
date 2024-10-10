#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data; // Can be any data
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;

void init_tree(NodePtr *start) {
    *start = NULL;
}

bool is_tree_empty(NodePtr root) {
    return root == NULL;
}

void insert_data(NodePtr *root, int data) {
    NodePtr new_node =(NodePtr) malloc(sizeof(NodeType));

    if (new_node == NULL)
    {
        return;
    }
    

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (is_tree_empty(*root))
    {
        *root = new_node;
    }
    else if (!is_tree_empty(*root))
    {
        NodePtr *trav = root;

        while (*trav != NULL)
        {
            if (data < (*trav)->data)
            {
                trav = &((*trav)->left);
            }
            else
            {
                trav = &((*trav)->right);
            }
            
        }
        
        insert_data(trav, data);
    }
    
}

void in_order(NodePtr root) {
    if (root != NULL) {
        in_order(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit root
        in_order(root->right); // Visit right subtree
    }
}

void pre_order(NodePtr root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit root
        pre_order(root->left);  // Visit left subtree
        pre_order(root->right); // Visit right subtree
    }
}

void post_order(NodePtr root) {
    if (root != NULL) {
        post_order(root->left);  // Visit left subtree
        post_order(root->right); // Visit right subtree
        printf("%d ", root->data);  // Visit root
    }
}



#endif