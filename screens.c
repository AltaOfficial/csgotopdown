#include <library.c>

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

void menus(int screen_num, os_type* os, Map maps[])
{
    int choice;
    
    // what the heck does load_maps do?????
    load_maps(maps);

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
                    menus(1, os, maps);
                break;
                case 2:
                    menus(2, os, maps);
                break;
                case 3:
                    exit(0);
                break;
                default:
                    menus(0, os, maps);
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
                global_var().env_var.control_players = true;
            }
            else if(choice == 2)
            {
                global_var().env_var.control_players = false;
            }



            game_start(&control_players);
            
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
            printf("            \t6. Color\n\n");

            printf("  Select Choice: ");
            scanf("%d", &choice);
	
	    // these are placeholder options, may not need some, example 'volume' and 'color' may not need
            switch(choice){
                case 1:
                    clear_screen(os);
                    main_menu(0, os, maps);
                break;

                case 2:
                    exit(0);
                break;

                case 3:
                    clear_screen(os);
                    printf("Friendly Fire?\n1. Yes\t2. No\n\nSelect Choice: ");
                    scanf("%d", &choice);
                    
                    if(){
                        global_var().env_var.friend_fire = true;
                    }else{
                        global_var().env_var.friend_fire = false;
                    }
                    main_menu(2, os, maps);
                break;

                // most likely need to be multible settings for bot chance stuff
                case 4:
                    clear_screen(os);
                    main_menu(2, os, maps);
                break;

                case 5:
                    clear_screen(os);
                    printf("Volume? \n 0 - 100\n\nSelect Choice: ");
                    scanf("%d", &choice);

                    if(choice => 0 && choice < 101){
                        global_var().env_var.volume = choice;
                    }
                    main_menu(2, os, maps);
                break;

                case 6:
                    clear_screen(os);
                    printf("Color? \n 1. Yes\t2. No\n\nSelect Choice: ");
                    scanf("%d", &choice);

                    if(choice == 1){
                        global_var().env_var.color = true;
                    }else{
                        global_var().env_var.color = false;
                    }
                    main_menu(2, os, maps);
                break;

                default:
                    clear_screen(os);
                    main_menu(2, os, maps);
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
                    menus(3, os, maps);
                break;
            }
        break;
    }
}
