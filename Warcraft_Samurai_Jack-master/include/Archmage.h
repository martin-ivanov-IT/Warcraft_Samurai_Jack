#ifndef ARCHMAGE_H_
#define ARCHMAGE_H_
#include"Archmage.h"
#include "Defines.h"
#include "Hero.h"
typedef struct Archmage{
    Hero base;
    int manaRegenModifier;
    
}Archmage;

void initArchmage(Archmage* archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier);
void archmageAction(Archmage* archmage, enum ActionType actionType);

#endif