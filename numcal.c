#include <stdio.h>
#define one_fill 8

int main()
{
    int hours_afk, resin_refilled;

    printf("How many hours were you AFK: ");
    scanf("%d", &hours_afk);

    resin_refilled = ((hours_afk * 60) / one_fill) * 1;

    printf("Total Resin Refilled is %d", resin_refilled);

    return 0;
}