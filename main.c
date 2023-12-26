#include <stdio.h>
#include "library.h"

int main () 
{
    char* OS;
    #ifdef __APPLE__ || __linux__
        OS = "Unix Based";
    #elif _WIN32 || _WIN64
        OS = "Windows";
    #endif

    printf("%s", OS);
    main_menu(1);
}