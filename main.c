#include <stdio.h>
#include "library.h"
#include "gameobjects.h"

int main () 
{
    Map maps[1];
    os_type OS = Windows;
    #if defined(__linux__) || defined(__APPLE__)
        OS = Unix;
    #elif defined(_WIN32) || defined(_WIN64)
        OS = Windows;
    #endif

    main_menu(1, &OS, maps);
}