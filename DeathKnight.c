#include"DeathKnight.h"
#include"Defines.h"

void initDeathKnight(DeathKnight* deathKnight, char* name, int maxMana, int baseManaRegenRate){
    heroBaseInit(deathKnight, name, maxMana, baseManaRegenRate);
    heroSpellsInit(deathKnight, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
                DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);

}

static void ultimateSpell(DeathKnight* deathKnight, Spell spell){
    if(isSpellCastable(deathKnight, spell)){
        takeMana(deathKnight, spell);
        printSpellAction(deathKnight, spell);
        printBonusSpellAction(deathKnight, deathKnight->spells[BASIC]);
    }
    else{
        printManaLack(deathKnight, spell);
    }
}

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