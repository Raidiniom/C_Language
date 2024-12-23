#include <stdio.h>
#include <stdlib.h>

#include "Enseran_Header.h"

int main() {

    Entity player = create_entity("Voltaire", 100.00, 25.55, 25.55, 0);

    World earth = let_there_be_light(8, player);

    set_difficulty(&earth);

    game_intro();

    while (earth.population[0].health != 0)
    {
        player_stats(earth.population[0]);

        if (check_player_exp(&earth.population[0]))
        {
            printf("%s, has leveled up!!!", earth.population[0].name);
        }

        

        debug_menu(&earth);
    }
    

    return 0;
}