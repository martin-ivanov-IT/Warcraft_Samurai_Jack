#ifndef DRAWRANGER_H_
#define DRAWRANGER_H_
#include"Hero.h"
typedef Hero DrawRanger;

void initDrawRanger(DrawRanger* drawRanger, char* name, int maxMana, int baseManaRegenRate);

#endif