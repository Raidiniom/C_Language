#include <stdio.h>
#include <stdbool.h>
#define daily 60 /* Commissions */
#define abyss 50 /* 3 stars == 50 primogems */
#define resin 1 /* 1 resin == 8 mins */

// Different Functions
void commission()
{
    int total, user_days;
    printf("How many days have you been playing Genshin: ");
    scanf("%d", &user_days);

    total = user_days * daily;

    printf("Total Primogems: %d", total);
}

void spiralabyss()
{
    int star_achieved, primo_rewards;
    printf("How many stars do you have in Spiral Abyss: ");
    scanf("%d", &star_achieved);

    primo_rewards = (star_achieved / 3) * abyss;

    printf("Total Primogems Reward: %d", primo_rewards);
}

void resinrefill()
{
    int hours_afk, resin_refilled;
    printf("How many hours are you AFK: ");
    scanf("%d", &hours_afk);

    resin_refilled = ((hours_afk * 60) / 8) * resin;

    printf("Total Resin Refilled: %d", resin_refilled);
}

// Main UI
int main()
{
    int cal_what;
    bool run = true;
    while (run == false)
    {
        printf("Enter [1 - Daily Commission | 2 - Spiral Abyss | 3 - Original Resin]: ");
        scanf("%d", &cal_what);

        switch (cal_what)
        {
            case 1:
                commission();
            break;
            case 2:
                spiralabyss();
            break;
            case 3:
                resinrefill();
            break;
            default:
                printf("Not An Options Sorry!");
            break;
        }
    }
    return 0;
}