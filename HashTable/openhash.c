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

bool insertElem(HashTable *ht, Student stud) {
    NodePtr new_node = malloc(sizeof(NodeType)), hold;
    
    new_node->stud = stud;
    
    if(ht->elems[getHash(stud)] == NULL) {
        new_node->next = ht->elems[getHash(stud)];
        ht->elems[getHash(stud)] = new_node;
    }
    else {
        hold = ht->elems[getHash(stud)];
        
        ht->elems[getHash(stud)] = ht->elems[getHash(stud)]->next;
        
        new_node->next = hold;
        ht->elems[getHash(stud)] = new_node;
    }
    
    ht->count++;
    
    return true;
}
bool deleteElem(HashTable *ht, Student stud);

void visualizeTable(HashTable ht) {
    for(int i = 0; i < max; i++) {
        if(ht.elems[i] == NULL) {
            printf("%d %d %.20s\n", i, 0, "Null");
        }
        else {
            while(ht.elems[i] != NULL) {
                printf("%d %d %.20s\n", i, ht.elems[i]->stud.stud_id, ht.elems[i]->stud.stud_name);
                
                ht.elems[i] = ht.elems[i]->next;
            }
        }
    }
}
