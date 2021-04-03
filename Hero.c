#include"Hero.h"
#include "Defines.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana, int inputManaRegenRate){
    strncpy(hero->name, inputName,MAX_HERO_NAME_SIZE);
    hero->maxMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
    hero->currMana = inputMaxMana;
}

void heroSpellsInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost,
                                const char *ultimateSpellName, int ultimateSpellManaCost)
{
    strncpy(hero->spells[BASIC].name, basicSpellName, MAX_SPELL_NAME_SIZE);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
    strncpy(hero->spells[ULTIMATE].name, ultimateSpellName, MAX_SPELL_NAME_SIZE);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;
}
void baseRegenerate(Hero* hero){
    hero->currMana += hero->manaRegenRate;
    if(hero->currMana > hero->maxMana){
        hero->currMana = hero->maxMana;
    }
}

void baseSpellAction(Hero* hero, Spell spell){
    if(isSpellCastable(hero, spell)){
        takeMana(hero, spell);
        printSpellAction(hero, spell);
    }
    else{
        printManaLack(hero, spell);
    }
}

void takeMana(Hero* hero, Spell spell){
    hero->currMana -= spell.manaCost;      
}

bool isSpellCastable(Hero* hero, Spell spell){
    if(hero->currMana >= spell.manaCost){
        return true;
    }
    return false;
}

void printSpellAction(Hero* hero, Spell spell){
    printf("%s casted %s for %d mana\n", hero->name, spell.name, spell.manaCost);
}

void printBonusSpellAction(Hero* hero, Spell spell){
    printf("%s casted %s for %d mana\n", hero->name, spell.name, BONUS_SPELL_MANA_COST);
}

void printManaLack(Hero* hero, Spell spell){
    printf("%s - not enough mana to cast %s\n", hero->name, spell.name);
}
