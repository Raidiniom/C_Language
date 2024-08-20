#include <stdio.h>
#include <stdlib.h>

int *newcol(int arry[], int count);

int main()
{
    int size, *newarry;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int list[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &list[i]);
    }
    
    newarry = newcol(list, size);

    printf("New Array Collection: ");
    for (int i = 0; i <= sizeof(newarry) / sizeof(int); i++)
    {
        printf("%d ", newarry[i]);
    }
    

    return 0;
}

int *newcol(int arry[], int count)
{
    int *hold = (int*)malloc(sizeof(int) * count), h = 0;

    if (arry[0] % 2 == 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (arry[i] % 2 == 0)
            {
                hold[h] = arry[i];
                h++;
            }   
        }
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            if (arry[i] % 2 != 0)
            {
                hold[h] = arry[i];
                h++;
            }   
        }
    }
    
    return hold;
}