#pragma once
#include <stdio.h>
#include <stdlib.h>
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

typedef enum {Unix, Windows} os_type;

typedef struct
{
    char* selectedMaps[1];
    bool* control_players;
    bool* friend_fire;
    int volume;
} env_vars;

os_type get_os();
int get_choice(int numItems, char* choices[]);
void clear_screen();
void print_menu_title(int menuNum);
void print(const char* text, ...);