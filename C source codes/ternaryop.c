#include <stdio.h>
#include <stdbool.h>
#define run true

int main()
{
    /*int money;

    while (run)
    {
        printf("Enter your Money: ");
        scanf("%d", &money);

        (money >= 250) ? printf("You have enough money") : printf("No Money");
    }*/

    int number, runs = 5;

    while (runs != 0)
    {
        printf("Enter a Number: ");
        scanf("%d", &number);

        int result = (number > 0) ? (number * number) : (number * -1);

        printf("%d\n", result);
        runs--;
    }

    return 0;
}