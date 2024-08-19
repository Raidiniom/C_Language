#include <stdio.h>
#include <stdlib.h>

/* 1 stamina = 6 minutes*/
float stamina(int hrs);

/* 1 resin = 8 minutes*/
float resin(int hrs);

/* 1 trailblazerpower = 6 minutes*/
float trapow(int hrs);

int main()
{
    int hrs;
    printf("Enter the hour/s you have AFK'd: ");
    scanf("%d", &hrs);

    printf("%.2f", stamina(hrs));

    return 0;
}

/* 1 stamina = 6 minutes*/
float stamina(int hrs)
{
    float result = hrs / 6;
    
    return result;
}

/* 1 resin = 8 minutes*/
float resin(int hrs);

/* 1 trailblazerpower = 6 minutes*/
float trapow(int hrs);