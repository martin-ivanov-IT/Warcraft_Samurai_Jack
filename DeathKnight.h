#ifndef DEATHKNIGHT_H_
#define DEATHKNIGHT_H_

#include"Hero.h"
typedef struct DeathKnight{
    Hero base;
}DeathKnight;

void initDeathKnight(DeathKnight* deathKnight, char* name, int maxMana, int baseManaRegenRate);

#endif