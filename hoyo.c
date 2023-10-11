#include <stdio.h>
#include <stdbool.h>
#define hrtomin 60
#define honkai 6
#define revhonkai 18
#define genshin 8

void trailblazer(int hours)
{
    int tp, rtp;

    tp = (hours * hrtomin) / honkai;
    rtp = (hours *hrtomin) / revhonkai;

    printf("Trailblazer Power: %d\nReserve Trailblazer Power: %d", tp, rtp);
}

void stamina(int hours)
{
    int sta;

    sta = (hours * hrtomin) / honkai;

    printf("Stamina: %d", sta);
}

void originalresin(int hours)
{
    int ore, cre;

    ore = (hours * hrtomin) / genshin;
    cre = ore / 40;

    printf("Original Resin: %d\nCondensed Resin: %d", ore, cre);
}

/*
    Note: tp - trailblazer power, the r is reserved. sta - stamina. or - original resin
    Honkai Star Rail - 1 tp -> 6 mins | 1 rtp -> 18 mins
    Honkai Impact 3rd - 1 sta -> 6 mins
    Genshin Impact - 1 or -> 8 mins
*/

int main()
{
    int pick, hours;
    bool run = true;

    while (run != true)
    {
        printf("Enter hours AFK'ed: "); 
        scanf("%d", &hours);
        printf("Pick -\n1 - Trailblazer Power\n2 - Stamina\n3 - Original Resin\nEnter number: ");
        scanf("%d", &pick);

        switch (pick)
        {
            case 1:
                trailblazer(hours);
            break;
            case 2:
                stamina(hours);
            break;
            case 3:
                originalresin(hours);
            break;
        
            default:
                printf("Invalid Input!!!");
            break;
        }
    }
    

    return 0;
}