#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
    #define ARROW_KEYDOWN 66
    #define ARROW_KEYUP 65
    #define ENTER_KEY 10
    #define HANDLE int
    #define STD_OUTPUT_HANDLE
    #define CONSOLE_CURSOR_INFO(...)
    typedef struct
    {
        bool bVisible;
        int dwSize;
    } CONSOLE_CURSOR_INFO;
    #define BACKGROUND_RED 
    #define BACKGROUND_BLUE 
    #define BACKGROUND_GREEN 
    #define FOREGROUND_RED
    #define FOREGROUND_GREEN
    #define FOREGROUND_BLUE
    #define COORD(...)
    typedef struct
    {                      
        short x;
        short y;
    } COORD;
    #define GetStdHandle(...) (2)
    #define SetConsoleTextAttribute(...)
    #define SetConsoleCursorPosition(...)
    #define SetConsoleCursorInfo(...)
#elif defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #include <conio.h>
    #include <stdbool.h>
    #define initscr()
    #define curs_set(...)
    #define cbreak()
    #define noecho()
    #define printw(...) (1)
    #define attroff(...)
    #define attron(...)
    #define move(...)
    #define clrtoeol()
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

os_type get_os()
{
    #if defined(__linux__) || defined(__APPLE__)
        return Unix;
    #elif defined(_WIN32) || defined(_WIN64)
        return Windows;
    #endif
}

// Windows solution to hiding the cursor
void show_cursor(bool isOn)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;
    SetConsoleCursorInfo(handle, &info);
}

// clears the whole line the cursor is on
void clear_line()
{
    printf("\x1b[2K");
}

void highlight_text_on()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

void highlight_text_off()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Returns which of the # of choices provided the user picked
int get_choice(int numItems, char* choices[])
{
    int choice;
    int highlight = 0;
    os_type OS = get_os();

    while(true)
    {
        for(int i = 0; i < numItems; i++)
        {
            if(i == highlight)
            {
                if(OS == Unix)
                {
                    clrtoeol();
                    move(7 + i, 0);
                    attron(A_REVERSE);
                    printw("* << %s >>",  choices[i]);
                    attroff(A_REVERSE);
                }
                else
                {
                    COORD coords = {0, 7 + i};
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
                    clear_line();
                    highlight_text_on();
                    printf("* << %s >>",  choices[i]);
                    highlight_text_off();
                }
            }
            else
            {
                if(OS == Unix)
                {
                    move(7 + i, 0);
                    clrtoeol();
                    printw("<< %s >>",  choices[i]);
                }
                else
                {
                    COORD coords = {0, 7 + i};
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
                    clear_line();
                    printf("<< %s >>",  choices[i]);
                }
            }
        }
        
        choice = getch();

        switch(choice)
        {
            // Up arrow pressed
            case ARROW_KEYUP:
                if(!(highlight == 0)) 
                {
                    highlight--;
                }
                break;

            // Down arrow pressed
            case ARROW_KEYDOWN:
                if(!(highlight == numItems - 1)) 
                {
                    highlight++;
                }
                break;
        }

        // Enter button pressed
        if(choice == ENTER_KEY)
        {
            break;
        }
    }
    return highlight;
}

void clear_screen()
{
    os_type OS = get_os();
    switch(OS)
    {
        case 0:
            system("clear");
        break;

        case 1:
            system("cls");
            highlight_text_off();
        break;
    }
}

void print_menu_title(int menuNum)
{
    os_type OS = get_os();
    char* mainMenuTitle = "   ___________ __________     ___        ____ \n  / ____/ ___// ____/ __ \\   |__ \\      / __ \\\n / /    \\__ \\/ / __/ / / /   __/ /_____/ / / /\n/ /___ ___/ / /_/ / /_/ /   / __/_____/ /_/ / \n\\____//____/\\____/\\____/   /____/    /_____/  \n                                              \n";
    switch(menuNum)
    {
        case 0:
            (OS == Unix) ? printw("%s", mainMenuTitle) : printf("%s", mainMenuTitle);
            break;

        case 1:
            // print options menu title
            break;
    }
}