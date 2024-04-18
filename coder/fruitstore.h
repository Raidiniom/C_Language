#ifndef FRUITSTORE_H_INCLUDED
#define FRUITSTORE_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef char String[50];

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    String name;
    Date expire;
    float price;
} Fruit;

typedef struct {
    Fruit *detail;
    int counter;
    int maxxer;
} Table;

// Functions
Date createDate(int day, int month, int year)
{
    Date init;

    init.day = day;
    init.month = month;
    init.year = year;

    return init;
}

Fruit createFruit(String name, Date expire, float price)
{
    Fruit init;

    strcpy(init.name, name);
    init.expire = expire;
    init.price = price;

    return init;
}

Table createTable(int maxxer)
{
    Table init;

    init.counter = 0;
    init.maxxer = maxxer;
    init.detail = malloc(sizeof(Fruit) * maxxer);

    return init;
}

Table expired(Table *present, String name)
{
    for(int i = 0; i < present->counter; ++i)
    {
        if(strcmp(present->detail[i].name, name) == 0)
        {
            for(int j = i; j < present->counter; ++j)
            {
                present->detail[j] = present->detail[j + 1];
            }
            (present->counter)--;
        }
    }
}

Table sortit(Table present) {
    // Insertion Sort based on expiry day
    for (int i = 1; i < present.counter; ++i) {
        Fruit hold = present.detail[i];
        int j = i - 1;
        while (j >= 0 && present.detail[j].expire.day > hold.expire.day) {
            present.detail[j + 1] = present.detail[j];
            j = j - 1;
        }
        present.detail[j + 1] = hold;
    }

    return present; // Return the sorted Table
}


void display(Table present)
{
    for(int i = 0; i < present.counter; ++i)
    {
        printf("Fruit: %s \n", present.detail[i].name);
        printf("Expiry Date: %d-%d-%d \n", present.detail[i].expire.month, present.detail[i].expire.day, present.detail[i].expire.year);
        printf("Sale Price: %.2f \n", present.detail[i].price);
        printf("\n");
    }
}

void add(Table *present, Fruit detail)
{
    if(present->counter < present->maxxer)
    {
        present->detail[(present->counter)++] = detail;
    }
}

#endif // FRUITSTORE_H_INCLUDED
