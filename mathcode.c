#include <stdio.h>

int main()
{
    int a, b, sum;

    printf("Enter integer A:");
    scanf("%d", &a);
    printf("Enter integer B:");
    scanf("%d", &b);

    sum = a + b;

    printf("Sum is %d", sum);

    return 0;
}