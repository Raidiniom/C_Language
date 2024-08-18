#include <stdio.h>

int main(){
    int height, width;

    printf("Input Height: ");
    scanf("%d", &height);
    printf("Input Width: ");
    scanf("%d", &width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}
