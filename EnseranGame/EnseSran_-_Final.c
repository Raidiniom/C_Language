#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
// #include <unistd.h>
#include <math.h>

//Global Declaration
void PresentMovesets();
void Grodinvoiceline_hurt();
void Exfridevoiceline_hurt();
void GrodinEntrance();
void ExfrideEntrance();
void AsvraseEntrance();
void Asvrasevoiceline_death();
void Exfridevoiceline_death();
void Grodinvoiceline_death();
void Asvrasevoiceline_atk();
void Grodinvoiceline_atk();
void Exfridevoiceline_atk();
void Asvrasevoiceline_hurt();
void PlayerDeath();
void artifact_list2();
void artifact_list1();
void PlayerHurt();
float player_hp(float Player_HP);
float player_atk(float Player_ATK);
float player_def(float Player_DEF);

float basic_enemy_stat_hp(float basic_enemy_HP);
float basic_enemy_stat_atk(float basic_enemy_ATK);
float basic_enemy_stat_def(float basic_enemy_DEF);

float elite_enemy_hp(float elite_enemy_HP);
float elite_enemy_atk(float elite_enemy_ATK);
float elite_enemy_def(float elite_enemy_DEF);

float boss_stat_hp(float boss_HP);
float boss_stat_atk(float boss_ATK);
float boss_stat_def(float boss_DEF);

int main()
{
    //Player Stats
    float Player_HP = player_hp(Player_HP);
    float Player_ATK = player_atk(Player_ATK);
    float Player_DEF = player_def(Player_DEF);
    int Player_Level = 1;
    int exp = 0;
    int exp_cap = 100;

    //Basic Enemy Stats
    float basic_enemy_HP = basic_enemy_stat_hp(basic_enemy_HP);
    float basic_enemy_ATK = basic_enemy_stat_atk(basic_enemy_ATK);
    float basic_enemy_DEF = basic_enemy_stat_def(basic_enemy_DEF);
    const int basic_exp_drop = 100;

    //Elite Enemy Stats - //Voltaire Part
    float elite_enemy_HP = elite_enemy_hp(elite_enemy_HP);
    float elite_enemy_ATK = elite_enemy_atk(elite_enemy_ATK);
    float elite_enemy_DEF = elite_enemy_def(elite_enemy_DEF);
    const int elite_exp_drop = 250;

    //Boss Stats
    float boss_HP = boss_stat_hp(boss_HP);
    float boss_ATK = boss_stat_atk(boss_ATK);
    float boss_DEF = boss_stat_def(boss_DEF);
    int boss_turn = 0;
    float spirit_siphon;

    //Interchangable Stats
    float target_HP;
    float target_ATK;
    float target_DEF;
    float target_total_DMG;

    //Battle choices & actions
    int move_set;
    int enemy_choice;
    int artifact_choice;
    int challenge_boss;
    bool boss_fight = false;

    //Cooldown & Buffer Status
    //Attack Part
    int atk_buff_turns = 0;
    int atk_buff_cd = 0;
    bool atk_buff_ready = true;
    bool atk_buff_active = false;
    float buffed_atk;
    float original_atk;

    //Defense Part
    int def_buff_turns = 0;
    int def_buff_cd = 0;
    bool def_buff_ready = true;
    bool def_buff_active = false;
    float buffed_def;
    float original_def;

    //Heavy Attack Part
    int heavy_atk_turns = 0;
    int heavy_atk_cd = 0;
    bool heavy_atk_ready = false;

    //Special Attack Part
    int special_atk_turns = 0;
    int special_atk_cd = 0;
    bool special_atk_ready = false;

    //SP
    int SP = 0;

    //Artifacts
    float artifact_heal;

    //Game Status
    bool game_over = false;
    bool game_over_boss = false;

    //Damage Formula
    float basic_attack_dmg;
    float heavy_attack_dmg;
    float special_attack_dmg;

    //Game Start
    printf("*-----* *-----* *-----* *-----* EnseSran *-----* *-----* *-----* *-----* \n \n");
    Sleep(1);
    printf("*----------------------------------------------------------------------------------* \n");
    printf("Meridia: It seems like you're new here Adventurer!!!\n");
    Sleep(2);
    printf("         Welcome to Grahont. A place of harmony and dissonance.");
    Sleep(2);
    printf("\n         As of right now, the Corrupt Vestibule has permeated its influence.");
    Sleep(2);
    printf("\n         The people of this land requires skilled Warriors.");
    printf("\n*----------------------------------------------------------------------------------*");
    Sleep(2);
    printf("\nYou can choose 3 enemies to fight.");
    Sleep(2);
    printf("\nDefeating basic and elite enemies will help you level up and will drop artifacts that can help you on our journey!");
    Sleep(3);
    printf("\nYou will end your journey once you defeat the final boss, Good luck, Adventurer!\n");
    Sleep(1);


    //The Whole Background Process for the Battle System
    while (Player_HP > 0 && boss_HP > 0 && game_over_boss == false)
    {

        //Save Original Stats
        original_atk = Player_ATK;
        original_def = Player_DEF;

        //ENEMY CHOICE
        Sleep(1);
        printf("*----------------------------------------------------------------------------------* \n");
        select_enemy:
        printf("[1]Basic Enemy \n[2]Elite Enemy \n[3]Boss\n");
        printf("Choose an enemy: ");
        scanf("%d",&enemy_choice);
        Sleep(1);
        system("cls");
        switch (enemy_choice)
        {
        case 1: //Player encounters the Grodin
            GrodinEntrance();
            target_HP = basic_enemy_HP;
            target_ATK = basic_enemy_ATK;
            target_DEF = basic_enemy_DEF;
            break;
        case 2: //Player encounters the Exfride
            ExfrideEntrance();
            target_HP = elite_enemy_HP;
            target_ATK = elite_enemy_ATK;
            target_DEF = elite_enemy_DEF;
            break;
        case 3: //Player encounters the Asvrase Core
            challenge_boss:
            printf("The Boss has very high stats and powerful skills");
            printf("\nAre you sure you want to challenge the boss?\n[1]Yes\n[2]No\n");
            scanf("%d",&challenge_boss);
            if (challenge_boss == 1)
            {
                system("cls");
                AsvraseEntrance();
                target_HP = boss_HP;
                target_ATK = boss_ATK;
                target_DEF = boss_DEF;
                boss_fight = true;
            }
            else if (challenge_boss == 2)
            {
                system("cls");
                Sleep(1);
                goto select_enemy;
            }
            else
            {
                system("cls");
                printf("Invalid Input.");
                Sleep(1);
                printf("\nPress any key to continue...");
                system("cls");
                goto challenge_boss;
            }
            break;
        default:
            printf("Invalid Input.");
            Sleep(1);
            printf("\nPress any key to continue...");
              
            system("cls");
            goto select_enemy;
        }

        //after choosing, short description of the enemy
        while (Player_HP > 0 && target_HP > 0)
        {
            //Damage Formula
            basic_attack_dmg = Player_ATK - target_DEF;
            heavy_attack_dmg = Player_ATK*1.75-target_DEF;
            special_attack_dmg = Player_ATK*4.5-target_DEF;

            //Game UI
            Sleep(1);
            choose_move:
            printf("\n*-------------------------------------------------------------------*\n");
            printf("Player Level : %d\n",Player_Level);
            printf("Player Exp: %d/%d\n",exp,exp_cap);
            printf("*-------------------------------------------------------------------*\n");
            printf("Your Stats:\t\t\tEnemy Stats: \n");
            printf("HP: %.2f\t\t\tHP: %.2f\n",Player_HP,target_HP);
            printf("Attack: %.2f\t\t\tAttack: %.2f\n",Player_ATK,target_ATK);
            printf("Defense: %.2f\t\t\tDefense: %.2f\n",Player_DEF,target_DEF);
            printf("SP: %d",SP);
            printf("\n*-------------------------------------------------------------------*\n");

            //Choose Move
            PresentMovesets();
            scanf("%d",&move_set);
            system("cls");
            switch (move_set)
            {
                case 1: //Basic Attack
                    if (basic_attack_dmg <= 0)
                    {
                        basic_attack_dmg = 0;
                    }
                    target_HP -= basic_attack_dmg;
                    Sleep(1);
                    printf("You've dealt %.2f DMG\n",basic_attack_dmg);
                    //Enemy Damage Taken
                    if (target_HP > 0)
                    {
                        if(enemy_choice  == 1)
                        {
                            Grodinvoiceline_hurt();
                        }
                        else if(enemy_choice == 2)
                        {
                            Exfridevoiceline_hurt();
                        }
                        else if(enemy_choice == 3)
                        {
                            Asvrasevoiceline_hurt();
                        }
                    }
                    break;
                case 2: //Buff basic Attack
                    if (atk_buff_cd == 0)
                    {
                        atk_buff_ready = true;
                    }
                    if (atk_buff_ready == true)
                    {
                        atk_buff_active = true;
                        if (atk_buff_active == true)
                        {
                            printf("\nYou've gained 50%% additional ATK for 3 turns\n");
                            buffed_atk = Player_ATK*1.5;
                            Player_ATK = buffed_atk;
                            atk_buff_cd += 5;
                            atk_buff_turns += 4;
                            atk_buff_ready = false;
                        }
                    }
                    else
                    {
                        printf("\nYou can't use this skill yet. This skill is on cooldown for %d turn(s).\n",atk_buff_cd);
                        goto choose_move;
                    }
                    break;
                case 3: //Buff base Defense
                    if (def_buff_cd == 0)
                    {
                        def_buff_ready = true;
                    }
                    if (def_buff_ready == true)
                    {
                        def_buff_active = true;
                        if (def_buff_active == true)
                        {
                            printf("\nYou've gained 50%% additional Defense for 3 turns\n");
                            buffed_def = Player_DEF*1.5;
                            Player_DEF = buffed_def;
                            def_buff_cd += 5;
                            def_buff_turns += 4;
                            def_buff_ready = false;
                        }
                    }
                    else
                    {
                        printf("\nYou can't use this skill yet. This skill is on cooldown for %d turn(s).\n",def_buff_cd);
                        goto choose_move;
                    }
                    break;
                case 4: //Heavy Attack
                    if (SP >= 2)
                    {
                        heavy_atk_ready = true;
                    }
                    if (heavy_atk_ready == true)
                    {
                        if (heavy_attack_dmg <= 0)
                        {
                            heavy_attack_dmg = 0;
                        }
                        target_HP -= heavy_attack_dmg;
                        printf("You've used your Heavy Attack.\nYou've dealt %.2f DMG",heavy_attack_dmg);
                        SP -= 3;
                        heavy_atk_ready = false;
                    }
                    else
                    {
                        printf("\nYou don't have enough SP to activate Heavy Attack! (2 SP required)\n");
                        printf("\nYour SP: %d\n",SP);
                        Sleep(1);
                        goto choose_move;
                    }
                    //Enemy dmg taken
                    if (target_HP > 0)
                    {
                        if(enemy_choice  == 1)
                        {
                            Grodinvoiceline_hurt();
                        }
                        else if(enemy_choice == 2)
                        {
                            Exfridevoiceline_hurt();
                        }
                        else if(enemy_choice == 3)
                        {
                            Asvrasevoiceline_hurt();
                        }
                    }
                    break;
                case 5: //Special Attack
                    if (SP >= 4)
                    {
                        special_atk_ready = true;
                    }
                    if (special_atk_ready == true)
                    {
                        if (special_attack_dmg <= 0)
                        {
                            special_attack_dmg = 0;
                        }
                        target_HP -= special_attack_dmg;
                        printf("You've used your Special Attack.\nYou've dealt %.2f DMG",special_attack_dmg);
                        SP -= 5;
                        special_atk_ready = false;
                    }
                    else
                    {
                        printf("\nYou don't have enough SP to activate Special Attack! (4 SP required)\n");
                        printf("\nYour SP: %d\n",SP);
                        Sleep(1);
                        goto choose_move;
                    }
                    //Enemy dmg taken
                    if (target_HP > 0)
                    {
                        if(enemy_choice  == 1)
                        {
                            Grodinvoiceline_hurt();
                        }
                        else if(enemy_choice == 2)
                        {
                            Exfridevoiceline_hurt();
                        }
                        else if(enemy_choice == 3)
                        {
                            Asvrasevoiceline_hurt();
                        }
                    }
                    break;
            }
            //Enemy Turn Attack
            if (target_HP > 0)
            {
                target_total_DMG = target_ATK-Player_DEF;
                if (target_total_DMG <= 0)
                {
                    target_total_DMG = 0;
                }
                Player_HP -= target_total_DMG;
                if(enemy_choice  == 1)
                {
                    Grodinvoiceline_atk();
                }
                else if(enemy_choice == 2)
                {
                    Exfridevoiceline_atk();
                }
                printf("\nEnemy dealt %.2f DMG\n",target_total_DMG);
                PlayerHurt();
            }
            //Boss Turn Attack
            if (enemy_choice == 3)
            {
                if (target_HP > 0)
                {
                    Asvrasevoiceline_atk();
                    Player_HP -= target_total_DMG;
                }
                boss_turn++;
                //Boss Skills
                if(Player_HP > 0)
                {
                    //Essence Draw
                    target_ATK *= 1.12;
                    Sleep(1);
                    printf("\nEssence Draw - Asvrase has increased his attack to %.2f",target_ATK);
                    //Spirit Siphon
                    if (boss_turn == 3)
                    {
                        spirit_siphon = Player_HP*0.15;
                        //S U C C
                        Player_HP -= spirit_siphon;
                        //H E A L
                        target_HP += spirit_siphon;
                        Sleep(1);
                        printf("\n\nAsvrase used Spirit Siphon and stole %.2f of your HP.",spirit_siphon);
                        spirit_siphon = 0;
                        boss_turn = 0;
                    }
                }
            }
            //Buff Reset and avoid making cd and turns negative
            atk_buff_cd--;
            if (atk_buff_cd <= 0)
            {
                atk_buff_cd = 0;
            }
            atk_buff_turns--;
            if (atk_buff_turns <= 0)
            {
                atk_buff_turns = 0;
            }
            def_buff_cd--;
            if (def_buff_cd <= 0)
            {
                def_buff_cd = 0;
            }
            def_buff_turns--;
            if (def_buff_turns <= 0)
            {
                def_buff_turns = 0;
            }
            //Remove Buffs
            if (atk_buff_turns == 1)
            {
                atk_buff_active = false;
                Player_ATK = original_atk;
            }
            if (def_buff_turns == 1)
            {
                def_buff_active = false;
                Player_DEF = original_def;
            }

            //Artifact Heal
            Player_HP += artifact_heal;

            //Adding SP every turn
            SP++;

            //ROUND OVER

            //Enemy death
            if (target_HP <= 0 && Player_HP > 0)
            {
                printf("\n\nYou've defeated the enemy!\n");
                if(enemy_choice  == 1)
                {
                    Grodinvoiceline_death();
                    exp += basic_exp_drop;
                    printf("\nYou've received %d EXP!",basic_exp_drop);
                    Sleep(1);
                }
                else if(enemy_choice == 2)
                {
                    Exfridevoiceline_death();
                    exp += elite_exp_drop;
                    printf("\nYou've received %d EXP!",elite_exp_drop);
                    Sleep(1);
                }
                else if (enemy_choice == 3)
                {
                    Asvrasevoiceline_death();
                    Sleep(1);
                    printf("\n\nYou've defeated Asvrase, You've reached the end of your journey!\n");
                    printf("================================== THE END ============================================\n\n");
                    game_over_boss = true;
                }

                //RESET BUFFS AND COOLDOWNS
                if (enemy_choice == 1 || enemy_choice == 2)
                {
                    //to continue the game
                    game_over = false;
                    while (game_over == false)
                    {
                        atk_buff_turns = 0;
                        atk_buff_cd = 0;
                        def_buff_turns = 0;
                        def_buff_cd = 0;
                        SP = 0;
                        if (atk_buff_active == true)
                        {
                            Player_ATK /= 1.5;
                        }
                        if (def_buff_active == true)
                        {
                            Player_DEF /= 1.5;
                        }
                        atk_buff_ready = true;
                        def_buff_ready = true;
                        heavy_atk_ready = false;
                        special_atk_ready = false;
                        game_over = true;
                    }
                    //to continue the game
                    game_over = false;
                }
                //EXP Formula
                if (exp >= exp_cap)
                {
                    float level_increase = floor(exp/exp_cap);
                    Player_Level += level_increase;
                    exp %= exp_cap;
                    //increase stats per level
                    for (int i = 1; i<=level_increase; i++)
                    {
                        //increase exp cap
                        exp_cap *= 1.2;
                        Player_HP += 40;
                        Player_ATK += 20;
                        Player_DEF += 5;
                    }
                    printf("\n\nYou've leveled up by %.f Level(s)!",level_increase);
                    printf("\nYou've gained %.2f HP",level_increase*40);
                    printf("\nYou've gained %.2f ATK",level_increase*20);
                    printf("\nYou've gained %.2f DEF\n",level_increase*5);
                    Sleep(1);
                }
                if (enemy_choice == 1 || enemy_choice == 2)
                {
                    //to continue the game
                    game_over = false;
                    while (game_over == false)
                    {
                        //Artifact Drop
                        printf("\nAfter you've defeated the enemy, you received an artifact which buffs your stats!\n");
                        if (enemy_choice == 1)
                        {
                            artifact_list1();
                            scanf("%d",&artifact_choice);
                            switch (artifact_choice)
                            {
                            case 1:
                                artifact_heal += 20;
                                printf("\nYou've chosen Artifact 1, You've gained the following effects:\n");
                                printf("Every turn, heals the player for 20 HP\n");
                                break;
                            case 2:
                                Player_ATK += Player_ATK*0.05;
                                printf("\nYou've chosen Artifact 2, You've gained the following effects:\n");
                                printf("+5%% OF TOTAL ATK\n");
                                break;
                            case 3:
                                Player_DEF += Player_DEF*0.05;
                                printf("\nYou've chosen Artifact 3, You've gained the following effects:\n");
                                printf("+5%% OF TOTAL DEFENSE\n");
                                break;
                            }
                        }
                        else if (enemy_choice == 2)
                        {
                            artifact_list2();
                            scanf("%d",&artifact_choice);
                            switch (artifact_choice)
                            {
                            case 1:
                                artifact_heal += 40;
                                printf("\nYou've chosen Artifact 1, You've gained the following effects:\n");
                                printf("Every turn, heals the player 40 HP\n");
                                break;
                            case 2:
                                Player_ATK += Player_ATK*0.10;
                                printf("\nYou've chosen Artifact 2, You've gained the following effects:\n");
                                printf("+10%% OF TOTAL ATK\n");
                                break;
                            case 3:
                                Player_DEF += Player_DEF*0.10;
                                printf("\nYou've chosen Artifact 3, You've gained the following effects:\n");
                                printf("+10%% OF TOTAL DEFENSE\n");
                                break;
                            }
                        }
                        printf("\nChoose Another Enemy: \n");
                        game_over = true;
                    }
                }
            }
            //Player Death
            else if (Player_HP <= 0)
            {
                PlayerDeath();
                Sleep(1);
                printf("\n\nYou've been killed, with no hero that will protect Grohont, Evil consumes all.\n");
                printf("================================== THE END ============================================\n\n");
                printf("lmao noob, skill issue");
            }
        }
    }
return 0;
}

void PresentMovesets()
{
    Sleep(1);
    printf("\nMoveset- \n");
    printf("*-------------------------------------------------------------------* \n");
    printf("[1]Basic Attack   - Deals 100%% of Total ATK Damage, \n");
    printf("[2]Buff Attack    - Gain 50%% Additional ATK for 3 Turns (5 Turn CD), \n");
    printf("[3]Buff Defense   - Gain 50%% Additional DEF for 3 Turns (5 Turn CD), \n");
    printf("[4]Heavy Attack   - Deals 175%% of your Total ATK Damage (2 SP), \n");
    printf("[5]Special Attack - Deals 450%% of your Total ATK Damage (4 SP), \n");
    printf("*-------------------------------------------------------------------* \n");
    printf("\nSelect Move: \n");
}

//Basic Enemy = Grodin, All voicelines
void GrodinEntrance()
{
    printf("Enemy Grodin has Appeared!\n");
    printf("\n*-* Grodin: !GROAL! *-* \n");
}

void Grodinvoiceline_atk()
{
    Sleep(1);
    printf("\n*-* Grodin: HRAAAKK!! *-* \n");
}

void Grodinvoiceline_hurt()
{
    Sleep(1);
    printf("\n*-* Grodin: KRII!! *-* \n");
}

void Grodinvoiceline_death()
{
    Sleep(1);
    printf("\n*-* Grodin: *WRYY* *-* \n");
    Sleep(1);
}

//Elite Enemy = Exfride, All voicelines
void ExfrideEntrance()
{
    printf("Enemy Exfride has Appeared!\n");
    printf("\n*-* Exfride: FURIOUS ROAR *-* \n");
}

void Exfridevoiceline_atk()
{
    Sleep(1);
    printf("\n*-* Exfride: HAOOO! *-* \n");
}

void Exfridevoiceline_hurt()
{
    Sleep(1);
    printf("\n*-* Exfride: GRAOR! *-* \n");
}

void Exfridevoiceline_death()
{
    Sleep(1);
    printf("\n*-* Exfride: *STONE RUMBLING* *-* \n");
    Sleep(1);
}

//Boss = Asvrase Core, All voicelines
void AsvraseEntrance()
{
    Sleep(1);
    printf("'You've challenged Asvrase'");
    printf("\n*-* Asvrase Core: OH! YOU'RE APPROACHING ME? *-* \n");
    Sleep(2);
    printf("\nAsvrase is drawing power from the essence of the world!");
    Sleep(2);
    printf("\n\nAsvrase gains the following effects: ");
    Sleep(2);
    printf("\nEssence Draw: Every Turn, Asvrase permanently increases his attack by 12%%.");
    Sleep(3);
    printf("\nSpirit Siphon: Every 3 Turns, Asvrase steals 15%% of the Player's HP for his own.\n");
    Sleep(3);
}

void Asvrasevoiceline_atk()
{
    Sleep(1);
    printf("\n*-* Asvrase Core: AN ANAMOLY LIKE YOU SHOULD PERISH *-* \n");
}

void Asvrasevoiceline_hurt()
{
    Sleep(1);
    printf("\n*-* Asvrase Core: INSOLENT FOOL! *-* \n");
}

void Asvrasevoiceline_death()
{
    Sleep(1);
    printf("\n*-* Asvrase Core: HOW? HOW? THIS SHOULD HAVE NEVER HAPPEN! \nI HAVE THE POWER OF A GOD *-* \n");
    Sleep(2);
}

//Player Hurt & Attack effort/grunt
void PlayerHurt()
{
    Sleep(1);
    printf("\n*-* You:OUEFF! *-* \n");
}

void PlayerDeath()
{
    Sleep(1);
    printf("\n*-* You:*EXHALING LAST BREATH* *-* \n");
    Sleep(1);
}
void artifact_list1()
{
    Sleep(1);
    printf("\nArtifacts- \n");
    printf("*------------------------------------------* \n");
    printf("[1]Every turn, heals the player for 20 HP, \n");
    printf("[2]+5%% OF TOTAL ATK, \n");
    printf("[3]+5%% OF TOTAL DEFENSE, \n");
    printf("*------------------------------------------* \n");
    printf("Choose an Artifact: \n");
    Sleep(1);
}

void artifact_list2()
{
    Sleep(1);
    printf("\nArtifacts- \n");
    printf("*------------------------------------------* \n");
    printf("[1]Every turn, heals the player for 40 HP, \n");
    printf("[2]+10%% OF TOTAL ATK, \n");
    printf("[3]+10%% OF TOTAL DEFENSE, \n");
    printf("*------------------------------------------* \n");
    printf("Choose an Artifact: \n");
    Sleep(1);
}
//player stats
float player_hp(float Player_HP)
{
    Player_HP = 300;
    return Player_HP;
}
float player_atk(float Player_ATK)
{
    Player_ATK = 50;
    return Player_ATK;
}
float player_def(float Player_DEF)
{
    Player_DEF = 35;
    return Player_DEF;
}
//basic enemy
float basic_enemy_stat_hp(float basic_enemy_HP)
{
    basic_enemy_HP = 100;
    return basic_enemy_HP;
}

float basic_enemy_stat_atk(float basic_enemy_ATK)
{
    basic_enemy_ATK = 60;
    return basic_enemy_ATK;
}

float basic_enemy_stat_def(float basic_enemy_DEF)
{
    basic_enemy_DEF = 25;
    return basic_enemy_DEF;
}
//elite enemy
float elite_enemy_hp(float elite_enemy_HP)
{
    elite_enemy_HP = 450;
    return elite_enemy_HP;
}

float elite_enemy_atk(float elite_enemy_ATK)
{
    elite_enemy_ATK = 135;
    return elite_enemy_ATK;
}

float elite_enemy_def(float elite_enemy_DEF)
{
    elite_enemy_DEF = 55;
    return elite_enemy_DEF;
}
//boss enemy
float boss_stat_hp(float boss_HP)
{
    boss_HP = 4500;
    return boss_HP;
}

float boss_stat_atk(float boss_ATK)
{
    boss_ATK = 250;
    return boss_ATK;
}

float boss_stat_def(float boss_DEF)
{
    boss_DEF = 300;
    return boss_DEF;
}
