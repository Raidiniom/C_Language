#include <stdio.h>

int sum(int arr[], int count);

int main()
{
    int size;

    printf("Enter how many values: ");
    scanf("%d", &size);

    int list[size];

    for(int i = 0; i < size; ++i)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &list[i]);
    }

    printf("List {");
    for(int y = 0; y < size; ++y)
    {
        if(y != 0)
        {
            printf(", ");
        }
        printf("%d", list[y]);
    }
    printf("}\n");

    printf("The sum of odd is %d.", sum(list, size));

    return 0;
}

int sum(int arr[], int count)
{
    int sum = 0;
    for(int i = 0; i < count; ++i)
    {
        if(arr[i] % 2 != 0)
        {
            sum += arr[i];
        }
    }

    return sum;
}