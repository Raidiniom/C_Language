#include <stdio.h>

int missing(int arr[], int count);

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int list[size];

    for(int i = 0; i < size; ++i)
    {
        printf("Enter element: ");
        scanf("%d", &list[i]);
    }
    
    printf("The missing number is: %d", missing(list, size));

    return 0;
}

int missing(int arr[], int count)
{
    int mir[count], sum = 0, msum = 0;
    for(int x = 0; x <= count; ++x)
    {
        mir[x] = x + 1;
    }

    for(int y = 0; y <= count; ++y)
    {
        msum += mir[y];
    }

    for(int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }

    int miss = msum - sum;
        
    return miss;
}