#include <stdio.h>

void kafkaline()
{
    printf("Before I joined the Stellaron Hunters, the nature of my work meant that I barely ever saw the same person twice.");
}

void yelanline()
{
    printf("The reason I'm willing to bet on you is because of your special status. I think it'll bring me a lot of leads that can get me closer to the truth... Heh, so, got any news for me today?");
}

int main()
{
    int pick;

    printf("Pick [ 1 - Kafka | 2 - Yelan]: ");
    scanf("%d", &pick);

    if (pick == 1)
    {
        kafkaline();
    }
    else if (pick == 2)
    {
        yelanline();
    }

    return 0;
}