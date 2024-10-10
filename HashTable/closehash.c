#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "closehash.h"

Student createStudent(int id, String name, String program, int year) {
    Student start;
    
    start.stud_id = id;
    strcpy(start.stud_name, name);
    strcpy(start.program, program);
    start.year = year;
    
    return start;
}

int getHash(Student stud) {
    return (stud.stud_id >> 2) % MAX;
}

void initDictionary(HashTable *ht) {
    ht->count = 0;
    

    for (int i = 0; i < MAX; i++)
    {
        ht->elems[i] = NULL;
    }
    
}

bool insertElem(HashTable *ht, Student stud) {
    
    int index = getHash(stud), original_index = index;

    while (ht->elems[index] != NULL && ht->elems[index]->status != deleted)
    {
        index = (index + 1) % MAX;

        if (index == original_index)
        {
            return false;
        }
        
    }
    
    NodePtr insert_this = malloc(sizeof(NodeType));

    if (insert_this == NULL)
    {
        return false;
    }

    insert_this->stud = stud;
    insert_this->status = close;

    insert_this->next = ht->elems[index];
    ht->elems[index] = insert_this;

    ht->count++;

    return true;
}

bool deleteElem(HashTable *ht, Student stud) {
    int index = getHash(stud);
    int original_index = index;

    while (ht->elems[index] != NULL)
    {
        if (ht->elems[index]->status == close && ht->elems[index]->stud.stud_id == stud.stud_id && strcmp(ht->elems[index]->stud.stud_name, stud.stud_name) == 0 )
        {
            ht->elems[index]->status = deleted;
            ht->count--;

            return true;
        }

        index = (index + 1) % MAX;


        if (index == original_index)
        {
            break;;
        }
        
        
    }
    
    
    return false;
}

void visualizeTable(HashTable ht) {
    for (int i = 0; i < MAX; i++) {
        if (ht.elems[i] == NULL) {
            printf("%d | Open\n", i);
        } else {
            if (ht.elems[i]->status == deleted)
            {
                printf("%d | Deleted \n", i);
            }
            else
            {
                printf("%d | %d %s - %s - %d\n", i, 
                ht.elems[i]->stud.stud_id, 
                ht.elems[i]->stud.stud_name, 
                ht.elems[i]->stud.program, 
                ht.elems[i]->stud.year);
            }
            
        }
    }
}


void check_status(HashTable ht) {
    for (int i = 0; i < MAX; i++) {
        if (ht.elems[i] == NULL) {
            printf("%d | Open\n", i);  // Slot is empty
        } else {
            switch (ht.elems[i]->status) {
                case open:
                    printf("%d | Open\n", i);
                    break;

                case close:
                    printf("%d | Closed\n", i);
                    break;

                case deleted:
                    printf("%d | Deleted\n", i);
                    break;

                default:
                    printf("%d | Unknown Status!\n", i);
                    break;
            }
        }
    }
}
