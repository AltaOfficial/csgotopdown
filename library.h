#pragma once
#include <stdbool.h>
#include "gameobjects.h"

typedef enum {Unix, Windows} os_type;

void main_menu(int screen_num, os_type* os, Map maps[]);
void game_start(bool* control_friendlys);
void display_world();