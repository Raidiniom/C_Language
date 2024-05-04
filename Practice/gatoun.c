#include <stdio.h>
#include <stdlib.h>

typedef char String[50];

typedef struct 
{
    String fname;
    String lname;
} Name;

typedef struct {
    Name pName;
    int id;
} Student;

typedef struct list {
    Student carolain;
    struct list *next;
} classList, *Class;

void add(Class *L, Student enrolle)
{
    Class newNode = malloc(sizeof(classList));

    newNode->carolain = enrolle;
    newNode->next = NULL;

    if (*L == NULL)
    {
        *L = newNode;
        return; 
    }

    Class trav = *L;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = newNode;
}

void insert(Class *L, int pos, Student enrolle)
{
    Class newNode = malloc(sizeof(classList));
    newNode->carolain = enrolle;
    Class trav = *L;
    int trkpos = 1;
    while (trav != NULL && trkpos < pos - 1)
    {
        trkpos++;
        trav = trav->next;
    }
    
    newNode->next = trav->next;
    trav->next = newNode;
}

void display(Class L)
{
    Class trav = L;
    while (trav != NULL)
    {
        printf("NAME:%s, %s \nID: %d\n", trav->carolain.pName.fname, trav->carolain.pName.lname, trav->carolain.id);
        trav = trav->next;
    }
    
}

int main()
{
    Class IT = NULL;

    Student stud1 = {{"Vo", "Rati"}, 1};
    Student stud2 = {{"Jo", "Gero"}, 2};
    Student stud3 = {{"Se", "Ceba"}, 3};
    Student stud4 = {{"Ce", "Boca"}, 4};
    Student stud5 = {{"Ca", "Dian"}, 6};

    add(&IT, stud1);
    add(&IT, stud2);
    add(&IT, stud3);
    add(&IT, stud4);

    printf("\nInitail List:\n");
    display(IT);

    insert(&IT, 3, stud5);

    printf("\nInserted List:\n");
    display(IT);

    return 0;
}