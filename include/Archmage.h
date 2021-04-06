#ifndef ARCHMAGE_H_
#define ARCHMAGE_H_
#include"Hero.h"
typedef struct Archmage{
    Hero base;
    int manaRegenModifier;
    
}Archmage;
void Archamge_ctor(Archmage* const archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier);
void initArchmage(Archmage* const archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier);

#endif