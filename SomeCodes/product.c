#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct {
    int day, month, year;    
} MyDate;

typedef struct {
    int id;
    String name;
    MyDate exp;
    float price;
} Product;

typedef struct {
    Product *prods;
    int count;
    int max;
} ProductList;

MyDate createDate(int day, int month, int year);
Product createProduct(int id, String name, MyDate exp, float price);
void initProductList(ProductList *list, int max);
ProductList createProductList(int max);
void populateProductList(ProductList *list);
void displayProductList(ProductList list);
//
int isLeapYear(int year);
int daysInMonth(int month, int year);
int dateDifference(MyDate d1, MyDate d2);
//
ProductList removeExpiredProducts(ProductList *list, MyDate d);
void removeProduct(ProductList *list, int ndx);
void addProductSorted(ProductList *list, Product p, MyDate exp);

void main() {
    ProductList myList;

    initProductList(&myList, 10);
    // myList = createProductList(10);

    printf("Product List\n");
    displayProductList(myList);
    printf("\nend of list\n\n");

    populateProductList(&myList);

    printf("Product List\n");
    displayProductList(myList);
    printf("\nend of list\n\n");

    ProductList expired = removeExpiredProducts(&myList, createDate(2, 4, 2024));
    
    printf("Product List Okay\n");
    displayProductList(myList);
    printf("\nend of list\n\n");
    
    printf("Product List Expired\n");
    displayProductList(expired);
    printf("\nend of list\n\n");
}

MyDate createDate(int day, int month, int year) {
    MyDate d;

    d.day = day;
    d.month = month;
    d.year = year;

    return d;
}

Product createProduct(int id, String name, MyDate exp, float price) {
    Product p;

    p.id = id;
    strcpy(p.name, name);
    p.exp = exp;
    p.price = price;
    
    return p;
}

void initProductList(ProductList *list, int max) {
    list->max = max;
    list->count = 0;
    list->prods = malloc(sizeof(Product) * max);
}

ProductList createProductList(int max) {
    ProductList list;

    list.max = max;
    list.count = 0;
    list.prods = malloc(sizeof(Product) * max);
    
    return list;
}

void populateProductList(ProductList *list) {
    list->prods[0] = createProduct(1, "Binangkal", createDate(15, 4, 2024), 15.00);
    list->prods[1] = createProduct(5, "Bingka", createDate(1, 4, 2024), 20.00);
    list->prods[2] = createProduct(12, "Banana", createDate(2, 4, 2024), 5.00);
    list->prods[3] = createProduct(56, "Baboy", createDate(15, 8, 2024), 120.00);
    list->prods[4] = createProduct(69, "Binignit", createDate(1, 1, 2023), 5000.00);
    list->count = 5;
}

void displayProductList(ProductList list) {
    printf("%5s - %20s - %15s - %s\n", "ID", "NAME", "DATE", "PRICE");
    for(int i = 0; i < list.count; ++i) {
        printf("%5d - %20s - %5s%02d/%02d/%04d - Php %.2f\n", list.prods[i].id, list.prods[i].name, "", 
                                                       list.prods[i].exp.day, list.prods[i].exp.month,
                                                       list.prods[i].exp.year, list.prods[i].price);
    }
}
//
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int dateDifference(MyDate date1, MyDate date2) {
    int days1 = date1.day + (date1.month - 1) * daysInMonth(date1.month, date1.year) + date1.year * 365;
    int days2 = date2.day + (date2.month - 1) * daysInMonth(date2.month, date2.year) + date2.year * 365;

    if (isLeapYear(date1.year) && date1.month < 3) {
        days1--;
    }
    if (isLeapYear(date2.year) && date2.month > 2) {
        days2++;
    }

    return days2 - days1;
}

ProductList removeExpiredProducts(ProductList *list, MyDate d) {
    ProductList expProd = createProductList(list->count);
    Product p;

    for(int i = 0; i < list->count; ++i) {
        if(dateDifference(list->prods[i].exp, d) > 0) {
            p = list->prods[i];
            removeProduct(list, i);
            addProductSorted(&expProd, p, d);
        }
    }
    return expProd;
}

void removeProduct(ProductList *list, int ndx) {
    for(int i = ndx; i < list->count; ++i) {
        list->prods[i] = list->prods[i+1];
    }  
    (list->count)--;
}

void addProductSorted(ProductList *list, Product p, MyDate exp) {
    int i;
    for(i = list->count; i > 0; i--) {
        if(dateDifference(list->prods[i].exp, exp) > 0) {
            list->prods[i] = list->prods[i-1];
        } else {
            break;
        }
    }
    list->prods[i] = p;
    (list->count)++;
}

