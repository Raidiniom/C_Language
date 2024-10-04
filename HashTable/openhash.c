#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "openhash.h"

Student createStudent(int id, String name, String program, int year) {
    Student start;
    
    start.stud_id = id;
    strcpy(start.stud_name, name);
    strcpy(start.program, program);
    start.year = year;
    
    return start;
}

int getHash(Student stud) {
    int sum = 0;
    
    for(int i = 0; i < 3; i++) {
        sum += stud.stud_name[i];
        sum += stud.program[i];
    }
    
    return sum % max;
}

void initDictionary(HashTable *ht) {
    ht->count = 0;
    
    for(int i = 0; i < max; i++) {
        ht->elems[i] = NULL;
    }
}

// bool insertElem(HashTable *ht, Student stud) {
//     NodePtr new_node = malloc(sizeof(NodeType)), hold;

//     if (new_node == NULL)
//     {
//         return false;
//     }
    
    
//     new_node->stud = stud;
    
//     int index = getHash(stud);

//     if(ht->elems[index] == NULL) {
//         new_node->next = ht->elems[index];
//         ht->elems[index] = new_node;
//     }
//     else {
//         hold = ht->elems[index];
        
//         ht->elems[index] = ht->elems[index]->next;
        
//         new_node->next = hold;
//         ht->elems[index] = new_node;
//     }
    
//     ht->count++;
    
//     return true;
// }

// More Efficient insert from chatgpt
bool insertElem(HashTable *ht, Student stud) {
    int hashIndex = getHash(stud);
    NodePtr new_node = malloc(sizeof(NodeType));
    
    if (!new_node) {
        return false;  // Memory allocation failed
    }

    // set the student info 
    new_node->stud = stud;

    // just insert front
    new_node->next = ht->elems[hashIndex];
    ht->elems[hashIndex] = new_node;

    // increase the count
    ht->count++;
    return true;
}


bool deleteElem(HashTable *ht, Student stud) {
    int index = getHash(stud);

    NodePtr curr = ht->elems[index], prev = NULL;

    while (curr != NULL)
    {
        if (curr->stud.stud_id == stud.stud_id) {
            if (curr->next == NULL)
            {
                ht->elems[index] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            
            free(curr);
            ht->count--;
            return true;
        }

        prev = curr;
        curr = curr->next;
    }
    
    return false;
}

void visualizeTable(HashTable ht) {
    printf("Count: %d\n", ht.count);
    for(int i = 0; i < max; i++) {
        if(ht.elems[i] == NULL) {
            printf("%d | %d %.20s | \n", i, 0, "Null");
        }
        else {
            printf("%d | ", i);
            while(ht.elems[i] != NULL) {
                printf("%d %.20s | ", ht.elems[i]->stud.stud_id, ht.elems[i]->stud.stud_name);
                
                ht.elems[i] = ht.elems[i]->next;
            }
            printf("\n");
        }
    }
}
