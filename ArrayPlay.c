#include <stdio.h>

int main()
{
    int my_fav[5], total_fav;

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

    for (int sum = 0; sum < 5; sum++)
    {
        total_fav += my_fav[sum];
    }

    printf("\nTotal of your Fav Numbers: %d", total_fav);

    return 0;
}