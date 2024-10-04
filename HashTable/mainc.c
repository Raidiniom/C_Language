#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "closehash.c"

int main() {

    HashTable closeTable;

    initDictionary(&closeTable);

    insertElem(&closeTable, createStudent(1, "Ab", "it", 2));
    insertElem(&closeTable, createStudent(2, "Cd", "is", 1));
    insertElem(&closeTable, createStudent(3, "Ef", "it", 2));
    insertElem(&closeTable, createStudent(4, "Gh", "cs", 2));
    insertElem(&closeTable, createStudent(5, "Ij", "it", 1));
    insertElem(&closeTable, createStudent(6, "Kl", "it", 2));

    insertElem(&closeTable, createStudent(10, "Mn", "it", 3));
    insertElem(&closeTable, createStudent(25, "Op", "is", 2));
    insertElem(&closeTable, createStudent(35, "Qr", "cs", 3));
    insertElem(&closeTable, createStudent(49, "St", "it", 2));
    insertElem(&closeTable, createStudent(53, "Uv", "cs", 1));
    insertElem(&closeTable, createStudent(16, "Wx", "sc", 2));

    printf("Initial Table\n");
    visualizeTable(closeTable);
    printf("Checking Statuses\n");
    check_status(closeTable);

    insertElem(&closeTable, createStudent(53, "Yz", "cs", 1));
    insertElem(&closeTable, createStudent(35, "AbC", "it", 2));

    printf("\nAdded student at occupied index Table\n");
    visualizeTable(closeTable);
    printf("Checking Statuses\n");
    check_status(closeTable);

    deleteElem(&closeTable, createStudent(1, "Ab", "it", 2));
    deleteElem(&closeTable, createStudent(4, "Gh", "cs", 2));
    deleteElem(&closeTable, createStudent(35, "AbC", "it", 2));

    printf("\nRemoved students from the Table\n");
    visualizeTable(closeTable);
    printf("Checking Statuses\n");
    check_status(closeTable);

    return 0;
}