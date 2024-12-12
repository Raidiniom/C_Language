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
    float health;
    float max_health;
    float attack;
    float defense;
    int level;
    float exp;
    float exp_cap;
    int skill_point;
    int skill_point_cap;
} Entity;

typedef struct {
    Entity *population;
    int max;
    int count;
} World;

World let_there_be_light(int number_enemies, Entity player) {
    World start_world;

    start_world.max = number_enemies + 1;
    start_world.count = 0;
    start_world.population = malloc(number_enemies * sizeof(Entity));
    start_world.population[0] = player;
    start_world.count++;

    return start_world;
}

Entity create_entity(String name, float health, float attack, float defense) {
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

    return start_entity;
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

bool delete_entity(World *earth) {
    if (earth->count > 0)
    {
        for (int i = 0; i < earth->count; i++)
        {
            if (earth->population[i].health <= 0)
            {
                for (int x = i; x < earth->count; x++)
                {
                    earth->population[x] = earth->population[x + 1];
                }
                
                earth->count--;

                i--;
            }
            
        }

        return true;
    }
    
    return false;
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
            printf("\nError input\n\n");
            goto choose_again;
            return false;
        break;
    }
}

void easy_mode(World *earth) {
    printf("\nPlaying in Easy Mode");
}

void normal_mode(World *earth) {
    printf("\nPlaying in Normal Mode");
}

void hard_mode(World *earth) {
    printf("\nPlaying in Hard Mode");
}

void game_intro() {
    printf("==================== Welcome to EnseSran ====================\n");
    Sleep(1);
    printf("This is a dungeon crawler game\n");
    Sleep(1);
    printf("==================== Have Fun Playing the Game ====================\n");
}

void player_stats(Entity player) {
    Sleep(1);
    printf("==============================\n%s\n Health: %.2f/%.2f EXP: %.2f/%.2f \n Attack: %.2f Defense: %.2f\n Skill Points: %d\n", 
    player.name, 
    player.health, 
    player.max_health,
    player.exp, 
    player.exp_cap, 
    player.attack, 
    player.defense, 
    player.skill_point); 
}

void display_entities(World earth) {
    for (int i = 0; i < earth.count; i++)
    {
        printf("%s %.2f %.2f %.2f %d\n", earth.population[i].name, earth.population[i].health, earth.population[i].attack, earth.population[i].defense, earth.population[i].skill_point);
    }
    
}

void debug_menu(World *earth) {
    int input;
    printf("Choose Actions:\n[0] - 10 dmg applied to player\n[1] - 20 exp added to player\n ");
    scanf("%d", &input);

    switch (input)
    {
        case 0:
        earth->population[0].health -= 10;
        break;

        case 1:
        earth->population[0].exp += 20;
        break;
    
    default:
        printf("Invalid Input");
        break;
    }
}

#endif