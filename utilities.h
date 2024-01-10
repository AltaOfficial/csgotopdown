#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
    #define ARROW_KEYDOWN 65
    #define ARROW_KEYUP 66
    #define ENTER_KEY 10
#elif defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #include <conio.h>
    #include <stdbool.h>
    #define initscr()
    #define curs_set(...)
    #define cbreak()
    #define noecho()
    #define printw(...)
    #define attroff(...)
    #define attron(...)
    #define move(...)
    #define endwin()
    #define ARROW_KEYDOWN 80
    #define ARROW_KEYUP 72
    #define ENTER_KEY 13
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
void show_cursor(bool isOn);
void clear_line();
void highlight_text_on();
void highlight_text_off();
int get_choice(int numItems, char* choices[]);
void clear_screen();
void print_menu_title(int menuNum);