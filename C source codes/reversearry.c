#include <stdio.h>
#include <stdlib.h>

int *doreverse(int arr[], int count);

int main()
{
    int size, *reverse;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int list[size];

    for(int i = 0; i < size; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &list[i]);
    }
    list[size] = -1;

    reverse = doreverse(list, size);

    printf("Original array: [");
    for(int x = 0; list[x] != -1; ++x)
    {
        if(x != 0)
        {
            printf(", ");
        }
        printf("%d", list[x]);
    }
    printf("]\n");

    printf("Reverse array: [");
    for(int x = 0; reverse[x] != -1; ++x)
    {
        if(x != 0)
        {
            printf(", ");
        }
        printf("%d", reverse[x]);
    }
    printf("]");

    return 0;
}

int *doreverse(int arr[], int count)
{
    int *temp = (int*)malloc(sizeof(int) * count), s = count - 1;

    for(int c = 0; arr[c] != -1; ++c, --s)
    {
        temp[c] = arr[s];
    }
    temp[count] = -1;

    return temp;
}