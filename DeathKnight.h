#ifndef DEATHKNIGHT_H_
#define DEATHKNIGHT_H_

#include"Defines.h"
#include"Hero.h"
typedef Hero DeathKnight;
void initDeathKnight(DeathKnight* deathKnight, char* name, int maxMana, int baseManaRegenRate);
void deathKnightAction(DeathKnight* deathKnight, enum ActionType actionType);


#endif