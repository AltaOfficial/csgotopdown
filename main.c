#include <stdio.h>
#include "library.h"
#include "gameobjects.h"
#include "screens.c"

int main () 
{
    Map maps[1];
    os_type OS = Windows;
    #if defined(__linux__) || defined(__APPLE__)
        OS = Unix;
    #elif defined(_WIN32) || defined(_WIN64)
        OS = Windows;
    #endif

    meuns(0, &OS, maps);
}
