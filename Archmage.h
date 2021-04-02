#ifndef ARCHMAGE_H_
#define ARCHMAGE_H_
#pragma pack(1)
#include"Hero.h"
#include"Defines.h"
typedef struct Archmage{
    Hero base;
    int manaRegenModifier;
}Archmage;

void initArchmage(Archmage* archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier);
void archmageAction(Archmage* archmage, enum ActionType actionType);

#endif