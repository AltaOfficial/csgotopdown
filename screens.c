#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameobjects.h"
#include "renderer.h"

typedef enum {Unix, Windows} os_type;

typedef struct{
    char* selectedMaps[1];
    bool* control_players;
    bool* friend_fire;
    int volume;
} env_vars;

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

void menus(int screen_num, os_type* os, Map maps[], env_vars* options)
{
    int choice;
    if (!options){
        env_vars options;
    }

    clear_screen(os);
    switch(screen_num)
    {
        case 0:
            printf("\t  .------------------------------------.\n");
            printf("\t  |                        _____     _ |\n");
            printf("\t  |                       / __  \\   | ||\n");
            printf("\t  |  ___ ___  __ _  ___   `' / /' __| ||\n");
            printf("\t  | / __/ __|/ _` |/ _ \\    / /  / _` ||\n");
            printf("\t  || (__\\__ \\ (_| | (_) | ./ /__| (_| ||\n");
            printf("\t  | \\___|___/\\__, |\\___/  \\_____/\\__,_||\n");
            printf("\t  |           __/ |                    |\n");
            printf("\t  |          |___/                     |\n");
            printf("\t  '------------------------------------'\n");
            printf("1. Start Game | 2. Options | 3. Exit Game\n\n");
            
            printf("  Select Choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    menus(1, os, maps, options);
                break;
                case 2:
                    menus(2, os, maps, options);
                break;
                case 3:
                    clear_screen(os);
                    exit(0);
                break;
                default:
                    menus(0, os, maps, options);
                break;
            }

        break;
        // Start Game
        case 1:
            printf("Control Friendly Team?\n\n");
            printf("1. Yes\n2. No\n\n");
            printf("  Select Choice: ");

            scanf("%d", &choice);
            if(choice == 1)
            {
                // Set control players to true in env struct
            }
            else if(choice == 2)
            {
                // Set control players to false in env struct
            }



            game_start(options->control_players);
            
        break;
        // Options
        case 2:
            printf("\t  .------------------------------------.\n");
            printf("\t  | _____       _   _                 |\n");
            printf("\t  ||  _  |     | | (_)                |\n");
            printf("\t  || | | |_ __ | |_ _  ___  _ __  ___ |\n");
            printf("\t  || | | | '_ \\| __| |/ _ \\| '_ \\/ __||\n");
            printf("\t  |\\ \\_/ / |_) | |_| | (_) | | | \\__ \\|\n");
            printf("\t  | \\___/| .__/ \\__|_|\\___/|_| |_|___/|\n");
            printf("\t  |      | |                          |\n");
            printf("\t  |      |_|                          |\n");
            printf("\t  '------------------------------------'\n");

            printf("1. Main Menu\t3. Friendly Fire\n");
            printf("2. Exit Game\t4. Choice chance\n");
            printf("            \t5. Volume\n");

            printf("  Select Choice: ");
            scanf("%d", &choice);
	
	    // Volume is a placeholder option and may not be used
            switch(choice){
                case 1:
                    menus(0, os, maps, options);
                break;

                case 2:
                    clear_screen(os);
                    exit(0);
                break;

                case 3:
                    printf("Friendly Fire?\n1. Yes\t2. No\n\nSelect Choice: ");
                    scanf("%d", &choice);
                    
                    if(choice == 1)
                    {
                        // change friendly fire in env struct to true
                    }
                    else if(choice == 2)
                    {
                        // change friendly fire in env struct to false
                    }
                    else
                    {
                        menus(2, os, maps, options);
                    }
                break;

                // most likely need to be multible settings for bot chance stuff
                case 4:
                    menus(2, os, maps, options);
                break;

                case 5:
                    printf("Volume? \n 0 - 100\n\nSelect Choice: ");
                    scanf("%d", &choice);

                    if(choice >= 0 && choice < 101){
                        // change volume to choice
                    }
                    menus(2, os, maps, options);
                break;

                default:
                    menus(2, os, maps, options);
                break;

            }

        break;

        case 3:
            printf("What Maps to you want to queue?\n\n");
            printf("1. Test Map\n");
            printf("2. Mirage\n\n");
            
            printf("  Select Choice: ");

            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    
                break;

                case 2:

                break;

                case 3:

                break;
                default:
                    menus(3, os, maps, options);
                break;
            }
        break;
    }
}
