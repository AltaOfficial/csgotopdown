#include <stdio.h>
#include "screens.h"
#include "gameobjects.h"
#include "utilities.h"

int main () 
{
    Map maps[1]; // How many total maps the player can choose from

    // Determining the operating system
    os_type OS = get_os();

    // Choosing how to start based on operating system
    if(OS == Unix)
    {
        initscr();
        curs_set(0);
        cbreak();
        noecho();
        menus(0, &OS, maps, NULL); // Since null is passed for options, a new options object will be created
        endwin();
    }
    else
    {
        show_cursor(false);
        menus(0, &OS, maps, NULL); // Since null is passed for options, a new options object will be created
    }

}
