#include <stdio.h>

int main()
{
    int size1, size2;

    printf("Enter 2d Array Size [x]: ");
    scanf("%d", &size1);
    printf("Enter 2d Array Size [y]: ");
    scanf("%d", &size2);

    int array[size1][size2];

    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            printf("Enter Element: ");
            scanf("%d", &array[i][j]);
        }
    }

    for (int x = 0; x <= size1; x++)
    {
        for (int y = 0; y <= size2; y++)
        {
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}