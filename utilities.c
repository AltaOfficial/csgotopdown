#include "renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#if defined(__linux__) || defined(__APPLE__)
    #include <ncurses.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

os_type get_os()
{
    #if defined(__linux__) || defined(__APPLE__)
        return Unix;
    #elif defined(_WIN32) || defined(_WIN64)
        return Windows;
    #endif
}

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
                    move(7 + i, 0);
                    clrtoeol();
                    attron(A_REVERSE);
                    printw("* << %s >>",  choices[i]);
                    attroff(A_REVERSE);
                }
                else
                {
                    // windows version of moving to a specific line
                    // windows version of clear to end of line
                    // windows version of reverse on
                    printf("* << %s >>",  choices[i]);
                    // windows version of reverse off
                }
            }
            else
            {
                move(7 + i, 0);
                if(OS == Unix)
                {
                    clrtoeol();
                    printw("* << %s >>",  choices[i]);
                }
                else
                {
                    // windows version of moving to a specific line
                    // windows version of clear to end of line
                    // windows version of reverse on
                    printf("* << %s >>",  choices[i]);
                    // windows version of reverse off
                }
            }
        }
        choice = getch();

        switch(choice)
        {
            // Up arrow pressed
            case 65:
                if(!(highlight == 0)) highlight--;
                break;

            // Down arrow pressed
            case 66:
                if(!(highlight == numItems - 1)) highlight++;
                break;
        }

        // Enter button pressed
        if(choice == 10)
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

void print(const char* text, ...)
{
    va_list ptr;
    va_start(ptr, text);

    char space[1000];

    os_type OS = get_os();
    (OS == Unix) ? printw("%s", text) : printf("%s", text);
}