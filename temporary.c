#include <stdio.h>

int main()
{
    long long number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 0; i <= number; i++)
    {
        printf("%d\n", i);
    }

    printf("\n");
    
    for (int x = number; x >= 0; x--)
    {
        printf("%d\n", x);
    }    

    return 0;
}