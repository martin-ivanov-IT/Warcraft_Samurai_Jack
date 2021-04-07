#include"Hero.h"

// assign values to the Hero struct elements which are read from the standard input
void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana, int inputManaRegenRate){
    strncpy(hero->name, inputName,MAX_HERO_NAME_SIZE);
    hero->maxMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
    hero->currMana = inputMaxMana;
}
// assign values to the Hero struct element spells (which is array of 2 Spell structs) which are defines
void heroSpellsInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost,
                                const char *ultimateSpellName, int ultimateSpellManaCost)
{
    strncpy(hero->spells[BASIC].name, basicSpellName, MAX_SPELL_NAME_SIZE);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
    strncpy(hero->spells[ULTIMATE].name, ultimateSpellName, MAX_SPELL_NAME_SIZE);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;
}
// action regenerate Mana, current mana is increased with mana regenerate rate, up to the enitial mana (max mana)
void baseRegenerate(Hero* hero){
    hero->currMana += hero->manaRegenRate;
    if(hero->currMana > hero->maxMana){
        hero->currMana = hero->maxMana;
    }
}
//returns true if spell is casted, false if not
bool baseSpellAction(Hero* hero, Spell spell){
    //if current mana is bigger than spell cost, cast the spell and print info who casted what for how much
    if(isSpellCastable(hero, spell)){
        takeMana(hero, spell);
        printSpellAction(hero, spell);
        return true;
    }
    // if NO enough Mana, print info who did NOt casted what
    else{
        printManaLack(hero, spell);
        return false;
    }
}
// decrease current mana with the spell cost
void takeMana(Hero* hero, Spell spell){
    hero->currMana -= spell.manaCost;      
}
// returns true if current mana is enough to cast the spell, false if not
bool isSpellCastable(Hero* hero, Spell spell){
    if(hero->currMana >= spell.manaCost){
        return true;
    }
    return false;
}
// who, casted what, for how much
void printSpellAction(Hero* hero, Spell spell){
    printf("%s casted %s for %d mana\n", hero->name, spell.name, spell.manaCost);
}
// who casted what for free
void printBonusSpellAction(Hero* hero, Spell spell){
    printf("%s casted %s for %d mana\n", hero->name, spell.name, BONUS_SPELL_MANA_COST);
}
// who did NOT casted what 
void printManaLack(Hero* hero, Spell spell){
    printf("%s - not enough mana to cast %s\n", hero->name, spell.name);
}

