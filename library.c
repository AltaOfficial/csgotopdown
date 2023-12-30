#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gameobjects.h"

// this struct needs to be changed, and I think that all the calls in 'screens.c' are the improper syntax
typedef struct{
    char map;
    bool control_players;
    bool friend_fire;
    bool color;
    int volume;
}env_var;

env_var options;

// this may not be needed in the future since 'screens.c' already has a maps option, as well as a struct holding a varible to which map is which.
void load_maps(Map* maps)
{
    int numOfMaps = 1;
    Map testMap = {
        "----------------\n|                |"
    };
    Map mirage = {
        "----------------\n|                |"
    };
    Map tempMaps[] = {testMap, mirage};
    for(int i = 0; i < numOfMaps; i++)
    {
        maps[i] = testMap;
    }
}



void game_start(bool* control_friendlys)
{
    
}
