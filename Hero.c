#include"Hero.h"
#include "Defines.h"
void heroBaseInit(Hero *hero, char *inputName, int inputMaxMana, int inputManaRegenRate){
    hero->name = inputName;
    hero->maxMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
}
