#ifndef OPENHASH_H
#define OPENHASH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 20

typedef char String[20];

typedef struct {
    int stud_id;
    String stud_name;
    String program;
    int year;
} Student;

typedef struct node {
    Student stud;
    struct node *next;
} NodeType, *NodePtr;

typedef struct {
    NodePtr elems[20];
    int count;
} HashTable;

Student createStudent(int id, String name, String program, int year);

int getHash(Student stud);

void initDictionary(HashTable *ht);

bool insertElem(HashTable *ht, Student stud);

// TODO: Create this
bool deleteElem(HashTable *ht, Student stud);

void visualizeTable(HashTable ht);


#endif