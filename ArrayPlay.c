#include <stdio.h>

int main()
{
    int my_fav[5];

    printf("Enter your 5 Favorite numbers: \n");
    for (int pos = 0; pos < 5; pos++)
    {
        scanf("%d", &my_fav[pos]);
    }

    printf("Here are your 5 Fav Numbers: \n");
    for (int ite = 0; ite < 5; ite++)
    {
        printf("%d, ", my_fav[ite]);
    }

    return 0;
}