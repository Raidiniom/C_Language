#ifndef CLOSEHASH_H
#define CLOSEHASH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

typedef char String[20];

typedef enum {
    open,
    close,
    deleted
} Flag;

typedef struct {
    int stud_id;
    String stud_name;
    String program;
    int year;
} Student;

typedef struct node {
    Student stud;
    Flag status;
    struct node *next;
} NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count;
} HashTable;

Student createStudent(int id, String name, String program, int year);

int getHash(Student stud);

void initDictionary(HashTable *ht);

bool insertElem(HashTable *ht, Student stud);
bool deleteElem(HashTable *ht, Student stud);

void visualizeTable(HashTable ht);

void check_status(HashTable ht);

#endif