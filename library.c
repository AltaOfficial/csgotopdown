#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gameobjects.h"

typedef enum {Unix, Windows} os_type;

void clear_screen(os_type* os)
{
    switch(*os)
    {
        case 0:
            system("clear");
        break;

        case 1:
            system("cls");
        break;
    }
}

void loadMaps(Map* maps)
{
    int numOfMaps = 1;
    Map testMap = {
        "----------------\n|                |"
    };
    Map mirage = {
        "----------------\n|                |"
    };
    Map tempMaps[] = {testMap, mirage};
    for(int i = 0; i < numOfMaps; i++)
    {
        maps[i] = testMap;
    }
}

void game_start(bool* control_friendlys)
{
    
}

void main_menu(int screen_num, os_type* os, Map maps[])
{
    
    bool control_players;
    int choice;
    loadMaps(maps);

    clear_screen(os);

    switch(screen_num)
    {
        case 1:
            printf("//==================//\n");
            printf("//      MENU        //\n");
            printf("//==================//\n");
            printf("1. Start Game\n");
            printf("2. Exit Game\n\n");
            printf("Select Choice: ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                main_menu(2, os, maps);
            }
            else if(choice == 2)
            {
                exit(0);
            }
        break;

        case 2:
            printf("//==================//\n");
            printf("//      MENU        //\n");
            printf("//==================//\n");
            printf("Control Friendly Team?\n\n");
            printf("Select Choice: ");
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

        case 3:

            printf("//==================//\n");
            printf("//      MENU        //\n");
            printf("//==================//\n");
            printf("What Maps to you want to queue?\n\n");
            printf("Select Choice: ");
            printf("1. Test Map\n");
            printf("2. Mirage\n");
            printf("3. Confirm\n");

            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    
                break;

                case 2:

                break;

                case 3:

                break;
            }
        break;
    }
}