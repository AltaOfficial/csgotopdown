#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameobjects.h"
#include "renderer.h"

typedef enum {Unix, Windows} os_type;
typedef struct{
    char selectedMaps;
    bool* control_players;
    bool* friend_fire;
    int volume;
} env_vars;

void menus(int screen_num, os_type* os, Map maps[], env_vars* options);