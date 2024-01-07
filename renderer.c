#include <stdio.h>
#include <stdbool.h>
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif


void display_world(char* map)
{
    
}

void game_start(bool* control_friendlys)
{

}