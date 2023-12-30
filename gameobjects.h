#pragma once
#include <stdbool.h>

typedef struct
{
    bool isTroll, isHacking, commonlyBuysArmor, commonlyBuysKit, commonlyBuysUtils, commonlyGoesAfk;
    float strengthLevel, disconnectCrashesChance, playerMoral, peeksMidChance;
    char* rank;
} Player;

typedef struct
{
    char* mapLayout;
} Map;

typedef struct
{
    float damage, range, fireRate;
    int price;
} Weapon;