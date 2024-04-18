#ifndef CARGOSHIP_H_INCLUDED
#define CARGOSHIP_H_INCLUDED

typedef char String[50];

typedef struct {
    // self explanatory
    int month;
    int year;
} Date;

typedef struct {
    String name; // product name
    String manu; // product manufacturer
    char type; // product type
    Date expire; // date expiry
    int weight; // product weight
} Product;

typedef struct {
    Product *detail;
    int str; // storage
    int cap; // ship capacity
    int ctr; // count
    int mxx; // max
    String shipname;
} Ship;

// Functions
Date createDate(int month, int year)
{
    Date start;

    start.month = month;
    start.year = year;

    return start;
}

Product createProduct(String name, String manu, char type, Date expire, int weight)
{
    Product start;

    strcpy(start.name, name);
    strcpy(start.manu, manu);
    start.type = type;
    start.expire = expire;
    start.weight = weight;

    return start;
}

Ship createShip(int cap, String shipname)
{
    Ship start;

    strcpy(start.shipname, shipname);
    start.mxx = cap;
    start.cap = cap;
    start.ctr = 0;
    start.str = 0;
    start.detail = malloc(sizeof(Product) * cap);

    return start;
}

void addCargo(Ship *muni, Product detail)
{
    if(muni->ctr < muni->mxx || muni->str <= muni->cap)
    {
        muni->detail[(muni->ctr)++] = detail;
        muni->str += detail.weight;
    }
    else
    {
        printf("Ship At Full Capacity");
    }
}

void viewCargo(Ship muni)
{
    printf("%s: %s | %s: %d\n---===---===---\n", "Ship Name", muni.shipname, "Ship Capacity", muni.cap);
    printf("%10s| %10s |%s| %10s |%s\n", "Product Name", "Manufacturer", "Type", "Date Expirey", "Weight");
    for(int i = 0; i < muni.ctr; ++i)
    {
        printf("%12s| %12s |  %c | %d-%d %6s|%d\n", muni.detail[i].name, muni.detail[i].manu, muni.detail[i].type, muni.detail[i].expire.month, muni.detail[i].expire.year, " ", muni.detail[i].weight);
    }
}




#endif // CARGOSHIP_H_INCLUDED
