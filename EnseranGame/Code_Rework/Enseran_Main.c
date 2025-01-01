#include <stdio.h>
#include <stdlib.h>

#include "Enseran_Header.h"

int main() {
    
    String player_name;

    game_intro();
    scanf("%s", &player_name);
    Entity player = create_entity(player_name, 100.00, 25.55, 25.55, 0);

    World earth = let_there_be_light(8);

    set_difficulty(&earth);

    // Game part
    while (player.health != 0 || earth_is_empty(earth))
    {
        enemy_display(earth.population[0]);

        player_stats(player);

        
        if (delete_entity(&earth, &player))
        {
            printf("\n\n%s, has defeated %s!!!\n\n", player.name, peak_entity(earth).name);
        }
        

        if (check_player_exp(&player))
        {
            printf("\n\n%s, has leveled up!!!\n\n", player.name);
        }

        debug_menu(&earth, &player);
    }

    if (earth_is_empty(earth))
    {
        printf("\n\n%s has rid the world of evil entities made by the all seeing and consuming void!!!\n\n", player.name);
    }
    else 
    {
        printf("\n\n%s try again next time in another world HAHAHAHAHAHA!!!!!!!\n\n", player.name);
    }
    

    return 0;
}