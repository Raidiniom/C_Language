#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fruitstore.h"

int main()
{
    Table myStore = createTable(5);
    Table sorted = createTable(5);

    add(&myStore, createFruit("Apple", createDate(24, 4, 2024), 25.25));
    add(&myStore, createFruit("Banana", createDate(18, 4, 2024), 50.99));
    add(&myStore, createFruit("Grape", createDate(13, 4, 2024), 34.45));
    add(&myStore, createFruit("Orange", createDate(24, 4, 2024), 30.25));
    add(&myStore, createFruit("Peach", createDate(15, 4, 2024), 42.99));

    printf("==> MY DISPLAY <==\n");
    display(myStore);

    printf("==> SORT EXPIRY <==\n");
    sorted = sortit(myStore);
    display(sorted);

    printf("==> Deleted <==\n");
    expired(&sorted, "Apple");
    expired(&sorted, "Grape");
    display(sorted);

    return 0;
}
