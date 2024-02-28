#include <stdio.h>

#define max 60

typedef char String[max];

typedef struct {
    int ID;
    String item_name;
    float price;
    int quantity;
    String supplier;
} Item;


void add(Item input[], int *count);
void search(Item input[], int *count);
void display(Item input[], int *count);
void report(Item input[], int count);


int main()
{
    int choice, count = 0;
    Item product[max];

    while (choice != 5)
    {
        printf("Inventory Management System\n1. Add new item\n2. Search item by ID\n3. Display inventory\n4. Generate report\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add(product, &count);
            break;
            case 2:
                search(product, &count);
            break;
            case 3:
                display(product, &count);
            break;
            case 4:
                report(product, count);
            break;
            case 5:
                printf("Exiting program.");
            break;
            default:
                choice = 5;
            break;
        }
    }

    return 0;
}

void display(Item input[], int *count)
{
    printf("Current inventory: \n");
    for(int pos = 0; pos < *count; ++pos)
    {
        printf("ID: %d\n", input[pos].ID);
        printf("Name: %s\n", input[pos].item_name);
        printf("Price: %.2f\n", input[pos].price);
        printf("Quantity: %d\n", input[pos].quantity);
        printf("Supplier: %s\n\n", input[pos].supplier);
    }
    printf("\n");
}

void add(Item input[], int *count)
{
    // ID
    printf("Enter the ID of the item: ");
    scanf("%d", &input[*count].ID);
    // Item Name
    printf("Enter the name of the item: ");
    scanf("%s", input[*count].item_name);
    // Price
    printf("Enter the price of the item: ");
    scanf("%f", &input[*count].price);
    // Quantity
    printf("Enter the quantity of the item: ");
    scanf("%d", &input[*count].quantity);
    // Supplier Name
    printf("Enter the supplier of the item: ");
    scanf("%s", input[*count].supplier);
    // End Message
    printf("Item added to inventory.\n\n");

    (*count)++;
}

void search(Item input[], int *count)
{
    int ID_hold;
    printf("Enter the ID of the item to search: ");
    scanf("%d", &ID_hold);
    // Loops through the Inventory
    for(int pos = 0; pos < *count; ++pos)
    {
        if(ID_hold == input[pos].ID)
        {
            printf("ID: %d\n", input[pos].ID);
            printf("Name: %s\n", input[pos].item_name);
            printf("Price: %.2f\n", input[pos].price);
            printf("Quantity: %d\n", input[pos].quantity);
            printf("Supplier: %s\n\n", input[pos].supplier);
        }
    }
}

void report(Item input[], int count)
{
    float total_price = 0;
    int total_quantity = 0;

    for(int pos = 0; pos < count; ++pos)
    {
        total_price += input[pos].price * input[pos].quantity;
        total_quantity += input[pos].quantity;
    }
    printf("Total sales: $%.2f\nTotal quantity: %d\n\n", total_price, total_quantity);
}
