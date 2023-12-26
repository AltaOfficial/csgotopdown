#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void game_start(bool* control_friendlys){

}

void display_world()
{

}

void main_menu(int screen_num)
{
    bool control_players;
    int choice;

    switch(screen_num)
    {
        case 1:
            printf("//==================//\n");
            printf("//      MENU        //\n");
            printf("//==================//\n");
            printf("1. Start Game\n");
            printf("2. Exit Game\n");
            scanf("%d", &choice);
            if(choice == 1)
            {
                main_menu(2);
            }else if(choice == 2)
            {
                exit(0);
            }
        break;

        case 2:
            printf("//==================//\n");
            printf("//      MENU        //\n");
            printf("//==================//\n");
            printf("Control Friendly Team?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            scanf("%d", &choice);
            if(choice == 1)
            {
                control_players = true;
                game_start(&control_players);
            }
            else if(choice == 2)
            {
                control_players = false;
                game_start(&control_players);
            }
        break;
    }
}