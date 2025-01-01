#ifndef ENSERAN_HEADER_H
#define ENSERAN_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

typedef char String[20];

typedef struct {
    String name;

    // Entity Status
    float health;
    float max_health;
    float attack;
    float defense;
    int level;
    float exp;
    float exp_cap;
    int skill_point;
    int skill_point_cap;

    // Entity Identifier
    int identifier;
} Entity;

typedef struct {
    Entity *population;
    int max;
    int count;
} World;

World let_there_be_light(int number_enemies) {
    World start_world;

    start_world.max = number_enemies + 1;
    start_world.count = 0;
    start_world.population = malloc(number_enemies * sizeof(Entity));

    return start_world;
}

Entity create_entity(String name, float health, float attack, float defense, int identifier) {
    Entity start_entity;
    
    strcpy(start_entity.name, name);
    start_entity.health = health;
    start_entity.max_health = health;
    start_entity.attack = attack;
    start_entity.defense = defense;
    start_entity.level = 1;
    start_entity.exp = 0;
    start_entity.exp_cap = 100;
    start_entity.skill_point = 0;
    start_entity.skill_point_cap = 5;
    start_entity.identifier = identifier;

    return start_entity;
}

Entity peak_entity(World earth) {
    return earth.population[0];
}

bool add_entity(World *earth, Entity entity) {
    if (earth->count < earth->max)
    {
        earth->population[earth->count] = entity;
        earth->count++;

        return true;
    }
    
    return false;
}

bool delete_entity(World *earth, Entity *player) {
    if (peak_entity(*earth).health <= 0)
    {
        for (int i = 0; i < earth->count; i++)
        {
            if (earth->population[i].health <= 0)
            {
                for (int x = i; x < earth->count; x++)
                {
                    earth->population[x] = earth->population[x + 1];
                }

                // Depending on the difficulty, each enemy will drop certain amount exp
                if (earth->population[i].identifier > 0 && earth->population[i].identifier <= 5)
                {
                    player->exp += 10;
                }
                
                earth->count--;
                i--;
            }
            
        }
        return true;
    }

    
    return false;
}

bool earth_is_empty(World earth) {
    return earth.count == 0;
}

bool check_player_exp(Entity *player) {
    if (player->exp >= player->exp_cap)
    {
        player->exp = fmod(player->exp, player->exp_cap);
        player->exp_cap += player->exp_cap * 0.26;

        player->attack += player->attack * 0.10;
        player->defense += player->defense * 0.05;
        player->max_health += player->max_health * 0.25;
        
        if (player->level % 2 != 0)
        {
            player->skill_point_cap += 1;
        }
        

        return true;
    }
    
    return false;
}

void set_difficulty(World *earth) {
    int difficulty;

    printf("1 -> Easy\n2 -> Normal\n3 -> Hard\n");

    choose_again:
    printf("Choose difficulty: ");
    scanf("%d", &difficulty);

    switch (difficulty)
    {
        case 1:
            easy_mode(earth);
            return true;
        break;

        case 2:
            normal_mode(earth);
            return true;
        break;

        case 3:
            hard_mode(earth);
            return true;
        break;
    
    default:
            printf("Error input\n");
            goto choose_again;
            return false;
        break;
    }
}

// 1 - 10, 1-5 normal enemy, 6-9 elite enemy, 10 being boss
void easy_mode(World *earth) {
    printf("\nPlaying in Easy Mode\n");
    
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));

    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));

    add_entity(earth, create_entity("Large Ogre", 200, 23.5, 25, 10));

}

// 11 - 20, 11-15 normal enemy, 16-19 elite enemy, 20 being boss
void normal_mode(World *earth) {
    printf("\nPlaying in Normal Mode\n");

    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));

    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));

    add_entity(earth, create_entity("Large Ogre", 200, 23.5, 25, 10));
}

// 21 - 30, 21-25 normal enemy, 26-29 elite enemy, 30 being boss
void hard_mode(World *earth) {
    printf("\nPlaying in Hard Mode\n");

    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));
    add_entity(earth, create_entity("Goblin", 45, 15, 5, 1));

    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));
    add_entity(earth, create_entity("Orc", 120, 19.5, 15, 6));

    add_entity(earth, create_entity("Gold Gilded Dragon", 1000, 23.5, 25, 10));
}

void game_intro() {
    printf("==================== Welcome to EnseSran ====================\n");
    Sleep(1);
    printf("This is a dungeon crawler game\n");
    Sleep(1);
    printf("==================== Have Fun Playing the Game ====================\n\n");

    printf("\nEnter Your Name: ");
}

void player_stats(Entity player) {
    Sleep(1);
    printf("\n==============================\n%s\n Health: %.2f/%.2f EXP: %.2f/%.2f \n Attack: %.2f Defense: %.2f\n Skill Points: %d\n", 
    player.name, 
    player.health, 
    player.max_health,
    player.exp, 
    player.exp_cap, 
    player.attack, 
    player.defense, 
    player.skill_point); 
}

void enemy_display(Entity enemy) {
    Sleep(1);
    printf("\n%s\n Health: %.2f/%.2f\n Attack: %.2f Defense: %.2f\n", enemy.name, enemy.health, enemy.max_health, enemy.attack, enemy.defense);
}

void display_entities(World earth) {
    for (int i = 0; i < earth.count; i++)
    {
        printf("%s %.2f %.2f %.2f %d\n", earth.population[i].name, earth.population[i].health, earth.population[i].attack, earth.population[i].defense, earth.population[i].skill_point);
    }
    
}

void player_actions(World *earth, Entity player) {
    int choice;

    choose_again:
    printf("\n=========================\nChoose Action:\n[0] - Deal %.2f Damage\nInput Here: ", player.attack);
    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            earth->population[0].health -= player.attack;
        break;

        // case 1:
        // break;

        // case 2:
        // break;

        // case 3:
        // break;

        // case 4:
        // break;

        // case 5:
        // break;
    
    default:
        printf("Invalid Input\n");
        goto choose_again;
        break;
    }
}

void debug_menu(World *earth, Entity *player) {
    int input;

    choose_again:
    printf("\n\nChoose Actions:\n[0] - 20 dmg applied to player\n[1] - 20 exp added to player\n[2] - 20 health applied to player\n[3] - 20 dmg applied to enemy\nInput Here: ");
    scanf("%d", &input);

    switch (input)
    {
        case 0:
            player->health -= 20;
        break;

        case 1:
            player->exp += 20;
        break;

        case 2:
            player->health += 20;
        break;

        case 3:
            earth->population[0].health -= 20;
        break;

        // case 4:
        // break;

        // case 5:
        // break;
    
    default:
        printf("Invalid Input\n");
        goto choose_again;
        break;
    }
}

#endif