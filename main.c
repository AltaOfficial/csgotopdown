#include <stdio.h>
#include "screens.h"
#include "gameobjects.h"
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main () 
{
    Map maps[1]; // How many total maps the player can choose from

    // Determining the operating system
    os_type OS = Windows;
    #if defined(__linux__) || defined(__APPLE__)
        OS = Unix;
    #elif defined(_WIN32) || defined(_WIN64)
        OS = Windows;
    #endif

    menus(0, &OS, maps, NULL); // Since null is passed for options, a new options object will be created
}
