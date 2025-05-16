#ifndef STOREFRONT_H_INCLUDED
#define STOREFRONT_H_INCLUDED

/*
    DO NOT TOUCH OR EDIT THE PRE-MADE FUNCTIONS!!!
*/

typedef char String[50];

typedef struct {
    int month, year;
} Date;

typedef struct {
    String type;
    String name;
    Date expiry;
    float cost;
    int stock;
} Product;

typedef struct {
    Product *storage;
    Product *display;
    int maxslots, countslot;
    float money;
} Store;

typedef struct {
    Product *inventory;
} Supplier;

Date createDate(int month, int year)
{
    Date start;

    start.month = month;
    start.year = year;

    return start;
}

Product createProduct(String type, String name, Date expiry, float cost, int stock)
{
    Product start;

    strcpy(start.type, type);
    strcpy(start.name, name);
    start.expiry = expiry;
    start.cost = cost;
    start.stock = stock;

    return start;
}

Store createStore(int maxslots)
{
    Store start;

    start.countslot = 0;
    start.maxslots = maxslots;
    start.money = 0;
    start.storage = malloc(sizeof(Product) * maxslots);
    start.display = malloc(sizeof(Product) * maxslots);

    return start;
}

Supplier startSupplier()
{
    Supplier seller;

    seller.inventory = malloc(sizeof(Lists) * 16);

    return seller;
}

void displayStore(Store thestore)
{
    for(int i = 0; i < thestore.maxslots; ++i)
    {
        //
    }
}

void displaySupplier(Supplier thesupplier)
{
    printf("%20s | %20s | %20s | %20s | %20s\n", "Name", "Type", "Expiry", "Cost", "Stock");
    for(int i = 0; i < thesupplier; ++i)
    {
        printf("%s %s %d/%d %.2f %d");
    }
}


/*
    DO NOT TOUCH OR EDIT THE PRE-MADE FUNCTIONS!!!
*/

#endif
