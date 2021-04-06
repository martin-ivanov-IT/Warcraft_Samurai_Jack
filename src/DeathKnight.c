#include"DeathKnight.h"

// assign values to the DrawRanger struct elements (Hero struct)
void initDeathKnight(DeathKnight* deathKnight, char* name, int maxMana, int baseManaRegenRate){
    // assign values to the Hero struct elements  which are read from the standard input
    heroBaseInit(deathKnight, name, maxMana, baseManaRegenRate);
    // assign values to the Hero struct element sells which are defines
    heroSpellsInit(deathKnight, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
                DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);

}
// if ultimate spell is casted (true is returned by function baseSpellAction), than bonus ultimate spell is casted for free
static void ultimateSpell(DeathKnight* deathKnight, Spell spell){
    if(baseSpellAction(deathKnight,spell)){
        printBonusSpellAction(deathKnight, deathKnight->spells[BASIC]);
    }
}
// take action, according to read action type
void deathKnightAction(DeathKnight* deathKnight, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        baseSpellAction(deathKnight, deathKnight->spells[BASIC]);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(deathKnight, deathKnight->spells[ULTIMATE]);
    }

    else if(actionType == REGENERATE_MANA){
        baseRegenerate(deathKnight);
    }
}