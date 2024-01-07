#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameobjects.h"
#include "renderer.h"
#include "utilities.h"

void menus(int screen_num, os_type* os, Map maps[], env_vars* options)
{
    int choice;
    if (options == NULL){
        env_vars options;
    }

    clear_screen();
    switch(screen_num)
    {
        case 0:
            // Main Menu
            print_menu_title(0);
            char* choices[] = {"Start Game", "Options", "Exit"};
            int choice = get_choice(3, choices);
            switch(choice)
            {
                case 0:
                    menus(1, os, maps, options);
                    break;
                
                case 1:
                    menus(2, os, maps, options);
                    break;

                default:
                    exit(0);
            }
            break;

        case 1:
            // Start Game
            break;
        
        case 2:
            // Options menu
            break;
    }

}
