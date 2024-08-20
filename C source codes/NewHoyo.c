#include <stdio.h>
#include <stdlib.h>

/* 1 stamina = 6 minutes*/
float stamina(float hrs);

/* 1 resin = 8 minutes*/
float resin(float hrs);

/* 1 trailblazerpower = 6 minutes*/
void trapow(float hrs);

void menu();

int main()
{
    int choice;
    float hours;
    menu();
    scanf("%d", &choice);

    printf("How many Hour/s AFK'd: ");
    scanf("%f", &hours);

    switch (choice)
    {
    case 1:
        printf("Stamina: %.2f\n", stamina(hours));
        break;

    case 2:
        printf("Resin: %.2f\n", resin(hours));
        break;

    case 3:
        trapow(hours);
        break;
    
    default:
        printf("Game is not Registered. Please Contact Support for Adding More Games!!!");
        break;
    }

    return 0;
}

/* 1 stamina = 6 minutes*/
float stamina(float hrs)
{   
    return (hrs * 60) / 6;
}

/* 1 resin = 8 minutes*/
float resin(float hrs)
{
    return (hrs * 60) / 8;
}

/* 1 trailblazerpower = 6 minutes*/
void trapow(float hrs)
{
    float base, reserve;

    if (((hrs * 60) / 6) < 240)
    {
        base = (hrs * 60) / 6;
    }
    else 
    {
        base = 240;
        reserve = ((hrs * 60) - 1440) / 18;
    }
    
    printf("\nTrailBlazer Power: %.2f\nIn Reserve: %.2f\n", base, reserve);
}

void menu()
{
    printf("Choose Game: ");
    printf("\n1 - Honkai Impact 3rd\n2 - Genshin Impact\n3 - Honkai: Star Rail\n");
    printf("Enter here -> ");
}